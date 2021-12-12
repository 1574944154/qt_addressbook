#ifndef PERSONMAPPER_H
#define PERSONMAPPER_H
#include <QtSql>
#include <QList>

#include "person.h"

class PersonMapper
{
public:
    PersonMapper();
    Person* getPersonById(int id);
    QList<Person> *getPersonsByUserId(int userId);
    QList<Person> *getPersons();
    QList<Person> *getPersonsByKeyWord(QString);
    QList<Person> *getPersonsByUserIdAndKeyWord(int userId, QString keyWord);
    QList<Person> *getPersonsByDepartmentId(int departmentId);
    QList<Person> *getPersonsByUserIdAndDepartmentId(int userId, int departmentId);
    bool insertPerson(Person person);
    bool deletePersonById(int id);
private:
    QSqlQuery query;
};

#endif // PERSONMAPPER_H
