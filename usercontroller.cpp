#include "usercontroller.h"

UserController::UserController()
{

}


User* UserController::login(QString username, QString password)
{
    User *user = userMapper.getUserByUsername(username);
    if(user==NULL){
        return NULL;
    }
    if(user->getPassword()!=password){
        return NULL;
    }
    return user;
}

QList<User>* UserController::getUsers()
{
    return userMapper.getUsers();
}

bool UserController::deleteUserById(int userId)
{
    bool res = personMapper.deletePersonById(userId);
    if(!res) return false;

    return userMapper.deleteUsersByUserId(userId);
}

bool UserController::addUser(User user)
{
    return userMapper.insertUser(user);
}
