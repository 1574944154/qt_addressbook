#include "UserService.h"

UserService::UserService()
{

}

User* UserService::login(QString username, QString password)
{
    if(username=="" || password=="") return nullptr;
    User *user = userMapper.getUserByUsername(username);
    if(user==nullptr) {
        return nullptr;
    }
    if(user->getPassword()!=password) {
        return nullptr;
    }
    return user;
}

QList<User>* UserService::getUsers()
{
    return userMapper.getUsers();
}

bool UserService::deleteUserById(int userId)
{
    bool res = personMapper.deletePersonById(userId);
    if(!res) return false;

    return userMapper.deleteUsersByUserId(userId);
}

bool UserService::addUser(User user)
{
    if(user.getUsername()=="" || user.getPassword()=="") return false;
    return userMapper.insertUser(user);
}
