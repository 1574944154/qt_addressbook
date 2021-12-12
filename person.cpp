#include "person.h"

Person::Person()
{

}

int Person::getId()
{
    return id;
}
QString Person::getName()
{
    return name;
}
QString Person::getPhone()
{
    return phone;
}
QString Person::getAddress()
{
    return address;
}
int Person::getUserId()
{
    return userId;
}

int Person::getDepartmentId()
{
    return departmentId;
}

void Person::setId(int id)
{
    this->id = id;
}
void Person::setName(QString name)
{
    this->name = name;
}
void Person::setPhone(QString phone)
{
    this->phone = phone;
}
void Person::setAddress(QString address)
{
    this->address = address;
}
void Person::setUserId(int userId)
{
    this->userId = userId;
}

void Person::setDepartmentId(int departmentId)
{
    this->departmentId = departmentId;
}


QDebug operator<<(QDebug debug, Person &person)
{
    debug << person.getId() << person.getName() << person.getPhone() << person.getAddress() ;
    return debug;
}

