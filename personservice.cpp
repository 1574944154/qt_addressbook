#include "personservice.h"

PersonService::PersonService()
{

}


Person* PersonService::getPersonById(int id)
{
    return personMapper.getPersonById(id);
}

bool PersonService::addPerson(Person person)
{
    if(person.getName()=="" || person.getPhone()=="") return false;
    return personMapper.insertPerson(person);
}


bool PersonService::deletePersonById(int id)
{
    return personMapper.deletePersonById(id);
}
QList<Person>* PersonService::getPersons()
{
    return personMapper.getPersons();
}

QList<Person>* PersonService::getPersonsByUserId(int userId)
{
    return personMapper.getPersonsByUserId(userId);
}
QList<Person>* PersonService::getPersonsByKeyWord(QString keyword)
{
    return personMapper.getPersonsByKeyWord(keyword);
}
QList<Person>* PersonService::getPersonsByUserIdAndKeyWord(int userId, QString keyWord)
{
    return personMapper.getPersonsByUserIdAndKeyWord(userId, keyWord);
}
QList<Person>* PersonService::getPersonsByDepartmentId(int departmentId)
{
    return personMapper.getPersonsByDepartmentId(departmentId);
}
QList<Person>* PersonService::getPersonsByUserIdAndDepartmentId(int userId, int departmentId)
{
    return personMapper.getPersonsByUserIdAndDepartmentId(userId, departmentId);
}
bool PersonService::insertPerson(Person person)
{
    return personMapper.insertPerson(person);
}
