#include "personcontroller.h"

PersonController::PersonController()
{

}


Person* PersonController::getPersonById(int id)
{
    return personMapper.getPersonById(id);
}

bool PersonController::addPerson(Person person)
{
    personMapper.insertPerson(person);
}


bool PersonController::deletePersonById(int id)
{
    return personMapper.deletePersonById(id);
}
QList<Person>* PersonController::getPersons()
{
    return personMapper.getPersons();
}

QList<Person>* PersonController::getPersonsByUserId(int userId)
{
    return personMapper.getPersonsByUserId(userId);
}
QList<Person>* PersonController::getPersonsByKeyWord(QString keyword)
{
    return personMapper.getPersonsByKeyWord(keyword);
}
QList<Person>* PersonController::getPersonsByUserIdAndKeyWord(int userId, QString keyWord)
{
    return personMapper.getPersonsByUserIdAndKeyWord(userId, keyWord);
}
QList<Person>* PersonController::getPersonsByDepartmentId(int departmentId)
{
    personMapper.getPersonsByDepartmentId(departmentId);
}
QList<Person>* PersonController::getPersonsByUserIdAndDepartmentId(int userId, int departmentId)
{
    return personMapper.getPersonsByUserIdAndDepartmentId(userId, departmentId);
}
bool PersonController::insertPerson(Person person)
{
    return personMapper.insertPerson(person);
}
