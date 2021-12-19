#include "loginwindow.h"


#include <QApplication>
#include <QtSql>


void openDatabase(QString databaseName)
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databaseName);
    if(!database.open())
    {
        qDebug() << "error: fail to open database.";
        exit(1);
    }else {
        qDebug() << "success to open database.";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    openDatabase("data.db");
    LoginWindow lw;
    lw.show();
    return a.exec();
}
