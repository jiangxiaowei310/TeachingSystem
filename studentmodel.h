#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QAbstractTableModel>
#include <QSqlDatabase>
#include <QList>

struct Student {
    QString id;
    QString name;
    QString gender;
    QString major;
    QString grade;
    QString phone;
    QString email;
};

class StudentModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit StudentModel(QObject *parent = nullptr);
    ~StudentModel();

    bool initDatabase();
    bool createTable();
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    
    bool addStudent(const Student &student);
    bool updateStudent(const QString &id, const Student &student);
    bool deleteStudent(const QString &id);
    QList<Student> searchStudents(const QString &keyword, int columnIndex);
    bool loadAllStudents();

private:
    QList<Student> m_students;
    QSqlDatabase m_db;
    QStringList m_columnNames;
};

#endif // STUDENTMODEL_H