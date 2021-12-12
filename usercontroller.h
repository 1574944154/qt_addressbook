#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include"user.h"
#include"usermapper.h"
#include"personmapper.h"

class UserController
{
public:
    UserController();

    User* login(QString, QString);

    QList<User>* getUsers();
    bool deleteUserById(int userId);
    bool addUser(User user);
private:
    UserMapper userMapper;
    PersonMapper personMapper;

};

#endif // USERCONTROLLER_H
