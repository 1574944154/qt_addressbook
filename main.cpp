#include "userwindow.h"
#include "loginwindow.h"
#include "usermapper.h"
#include "personmapper.h"

#include <QApplication>
#include <QtSql>
#include <QDebug>
#include <QList>

QSqlDatabase openDatabase(QString databaseName)
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
    return database;
}

void databaseTest()
{
    QSqlDatabase database = openDatabase("data.db");
    QSqlQuery query;
    query.prepare("select * from user where username=:username;");
    query.bindValue(":username", "1574944154");
    query.exec();
    while(query.next())
    {
        QString username = query.value(0).toString();
        QString password = query.value(1).toString();
        bool enabled = query.value(2).toBool();
        qDebug() << username << password << enabled << "\n";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase database = openDatabase("data.db");
    LoginWindow lw;
    lw.show();
    return a.exec();
//    openDatabase("data.db");
//    PersonMapper personMapper;

//    QList<Person> *persons;
//    persons = personMapper.getPersonsByKeyWord("1");
//    for(auto person:*persons)
//    {
//        qDebug() << person;
//    }
//    return 0;
}
