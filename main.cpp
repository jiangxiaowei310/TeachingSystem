#include "mainwindow.h"
#include "loginwindow.h"
#include "teachermainwindow.h"
#include "studentmainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    a.setStyle(QStyleFactory::create("Fusion"));
    
    LoginWindow login;
    if (login.exec() != QDialog::Accepted) {
        return 0;
    }
    
    QString username = login.getUsername();
    UserRole role = login.getUserRole();
    
    switch (role) {
        case UserRole::Admin: {
            MainWindow w;
            w.show();
            return a.exec();
        }
        case UserRole::Teacher: {
            TeacherMainWindow w(username);
            w.show();
            return a.exec();
        }
        case UserRole::Student: {
            StudentMainWindow w(username);
            w.show();
            return a.exec();
        }
        default: {
            MainWindow w;
            w.show();
            return a.exec();
        }
    }
}