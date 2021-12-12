#ifndef PERSONCONTROLLER_H
#define PERSONCONTROLLER_H
#include "personmapper.h"
#include "person.h"


class PersonController
{
public:
    PersonController();
    Person* getPersonById(int id);
    bool addPerson(Person person);
    bool deletePersonById(int id);
    QList<Person> *getPersons();


    QList<Person> *getPersonsByUserId(int userId);
    QList<Person> *getPersonsByKeyWord(QString);
    QList<Person> *getPersonsByUserIdAndKeyWord(int userId, QString keyWord);
    QList<Person> *getPersonsByDepartmentId(int departmentId);
    QList<Person> *getPersonsByUserIdAndDepartmentId(int userId, int departmentId);
    bool insertPerson(Person person);
private:
    PersonMapper personMapper;
};

#endif // PERSONCONTROLLER_H
