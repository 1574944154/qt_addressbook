#ifndef USERMAPPER_H
#define USERMAPPER_H
#include <QtSql>
#include "user.h"


class UserMapper
{
public:
    UserMapper();
    User* getUserByUsername(QString username);
    QList<User>* getUsers();
    bool insertUser(User &user);
    bool deleteUsersByUserId(int userId);
private:
    QSqlQuery query;
};

#endif // USERMAPPER_H
