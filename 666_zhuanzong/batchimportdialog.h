#ifndef BATCHIMPORTDIALOG_H
#define BATCHIMPORTDIALOG_H

#include <QDialog>
#include <QString>
#include <QList>
#include <QStringList>

namespace Ui { class BatchImportDialog; }
//批量导入学生对话框类
//支持 CSV 文件导入，自动创建学院、专业、班级，自动生成用户账号（触发器）
class BatchImportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BatchImportDialog(QWidget *parent = nullptr);
    ~BatchImportDialog();

    //获取选择的文件路径，@return 文件路径字符串
    QString getFilePath() const;

private slots:
    void on_browseBtn_clicked();//浏览文件按钮点击槽函数，打开文件选择框，仅选择 CSV 格式文件
    void on_okBtn_clicked();//确定（导入）按钮点击槽函数，读取CSV → 校验 → 入库
    void on_cancelBtn_clicked();//取消按钮点击槽函数，关闭对话框，取消导入操作

private:
    Ui::BatchImportDialog *ui;
    QString m_filePath;// 保存用户选择的文件路径

    QList<QStringList> readFile(const QString &path);//通用文件读取（预留，本项目不用）
    QList<QStringList> readCsv(const QString &path);// 读取 CSV 文件核心函数， path CSV 文件路径，
    //return 二维列表，每一行是一个字符串列表
    //QList<QStringList> readExcel(const QString &path);
};

#endif // BATCHIMPORTDIALOG_H
