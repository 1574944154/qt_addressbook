#include "user.h"

User::User()
{

}
User::User(QString username, QString password, int type)
{
    this->username = username;
    this->type = type;
    this->password = password;
}

QString User::getUsername()
{
    return username;
}
QString User::getPassword()
{
    return password;
}
int User::getType()
{
    return type;
}
void User::setUsername(QString username)
{
    this->username = username;
}
void User::setPassword(QString password)
{
    this->password = password;
}
void User::setType(int type)
{
    this->type = type;
}
void User::setId(int id)
{
    this->id = id;
}
int User::getId()
{
    return id;
}
