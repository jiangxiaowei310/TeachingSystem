#include "studentmodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

StudentModel::StudentModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_columnNames << "学号" << "姓名" << "性别" << "专业" << "年级" << "电话" << "邮箱";
}

StudentModel::~StudentModel()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool StudentModel::initDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("students.db");
    
    if (!m_db.open()) {
        qDebug() << "数据库打开失败:" << m_db.lastError().text();
        return false;
    }
    
    return createTable();
}

bool StudentModel::createTable()
{
    QSqlQuery query;
    QString sql = "CREATE TABLE IF NOT EXISTS students ("
                  "id TEXT PRIMARY KEY,"
                  "name TEXT NOT NULL,"
                  "gender TEXT,"
                  "major TEXT,"
                  "grade TEXT,"
                  "phone TEXT,"
                  "email TEXT)";
    
    if (!query.exec(sql)) {
        qDebug() << "创建表失败:" << query.lastError().text();
        return false;
    }
    
    return loadAllStudents();
}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_students.count();
}

int StudentModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_columnNames.count();
}

QVariant StudentModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        const Student &student = m_students[index.row()];
        switch (index.column()) {
        case 0: return student.id;
        case 1: return student.name;
        case 2: return student.gender;
        case 3: return student.major;
        case 4: return student.grade;
        case 5: return student.phone;
        case 6: return student.email;
        }
    }
    
    return QVariant();
}

QVariant StudentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return m_columnNames[section];
        } else {
            return section + 1;
        }
    }
    return QVariant();
}

bool StudentModel::addStudent(const Student &student)
{
    QSqlQuery query;
    query.prepare("INSERT INTO students (id, name, gender, major, grade, phone, email) "
                  "VALUES (:id, :name, :gender, :major, :grade, :phone, :email)");
    query.bindValue(":id", student.id);
    query.bindValue(":name", student.name);
    query.bindValue(":gender", student.gender);
    query.bindValue(":major", student.major);
    query.bindValue(":grade", student.grade);
    query.bindValue(":phone", student.phone);
    query.bindValue(":email", student.email);
    
    if (!query.exec()) {
        qDebug() << "插入失败:" << query.lastError().text();
        return false;
    }
    
    beginInsertRows(QModelIndex(), m_students.count(), m_students.count());
    m_students.append(student);
    endInsertRows();
    
    return true;
}

bool StudentModel::updateStudent(const QString &id, const Student &student)
{
    QSqlQuery query;
    query.prepare("UPDATE students SET name=:name, gender=:gender, major=:major, "
                  "grade=:grade, phone=:phone, email=:email WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":name", student.name);
    query.bindValue(":gender", student.gender);
    query.bindValue(":major", student.major);
    query.bindValue(":grade", student.grade);
    query.bindValue(":phone", student.phone);
    query.bindValue(":email", student.email);
    
    if (!query.exec()) {
        qDebug() << "更新失败:" << query.lastError().text();
        return false;
    }
    
    for (int i = 0; i < m_students.count(); i++) {
        if (m_students[i].id == id) {
            m_students[i] = student;
            emit dataChanged(index(i, 0), index(i, columnCount()-1));
            break;
        }
    }
    
    return true;
}

bool StudentModel::deleteStudent(const QString &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM students WHERE id=:id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "删除失败:" << query.lastError().text();
        return false;
    }
    
    for (int i = 0; i < m_students.count(); i++) {
        if (m_students[i].id == id) {
            beginRemoveRows(QModelIndex(), i, i);
            m_students.removeAt(i);
            endRemoveRows();
            break;
        }
    }
    
    return true;
}

QList<Student> StudentModel::searchStudents(const QString &keyword, int columnIndex)
{
    QList<Student> results;
    for (const Student &s : m_students) {
        QString value;
        switch (columnIndex) {
        case 0: value = s.id; break;
        case 1: value = s.name; break;
        case 2: value = s.gender; break;
        case 3: value = s.major; break;
        case 4: value = s.grade; break;
        case 5: value = s.phone; break;
        case 6: value = s.email; break;
        }
        if (value.contains(keyword, Qt::CaseInsensitive)) {
            results.append(s);
        }
    }
    return results;
}

bool StudentModel::loadAllStudents()
{
    QSqlQuery query("SELECT * FROM students");
    m_students.clear();
    
    while (query.next()) {
        Student s;
        s.id = query.value(0).toString();
        s.name = query.value(1).toString();
        s.gender = query.value(2).toString();
        s.major = query.value(3).toString();
        s.grade = query.value(4).toString();
        s.phone = query.value(5).toString();
        s.email = query.value(6).toString();
        m_students.append(s);
    }
    
    emit layoutChanged();
    return true;
}