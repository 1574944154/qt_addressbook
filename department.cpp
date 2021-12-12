#include "department.h"

Department::Department()
{

}


int Department::getId()
{
    return id;
}
QString Department::getName()
{
    return name;
}

void Department::setId(int id)
{
    this->id = id;
}
void Department::setName(QString name)
{
    this->name = name;
}
