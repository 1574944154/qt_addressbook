#include "usermapper.h"

UserMapper::UserMapper()
{

}

User* UserMapper::getUserByUsername(QString username)
{
    User *user = new User;

    query.prepare("select * from user where username=?;");
    query.bindValue(0, username);
    query.exec();
    if(query.next())
    {
        int id = query.value(0).toInt();
        QString password = query.value(2).toString();
        int type = query.value(3).toBool();
        user->setUsername(username);
        user->setPassword(password);
        user->setType(type);
        user->setId(id);
        return user;
    }
    else
        return NULL;
}

bool UserMapper::insertUser(User &user)
{
    query.prepare("INSERT INTO user (username, password, type) VALUES (?, ?, ?);");
    query.bindValue(0, user.getUsername());
    query.bindValue(1, user.getPassword());
    query.bindValue(2, user.getType());
    if(query.exec())
    {
        return true;
    }else{
        return false;
    }
}

QList<User>* UserMapper::getUsers()
{
    QList<User> *users = new QList<User>();
    query.prepare("SELECT * FROM user;");
    query.exec();
    while (query.next()) {
        User *user = new User();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString username = query.value(query.record().indexOf("username")).toString();
        QString password = query.value(query.record().indexOf("password")).toString();
        int type = query.value(query.record().indexOf("type")).toInt();

        user->setId(id);
        user->setUsername(username);
        user->setPassword(password);
        user->setType(type);

        users->append(*user);
    }
    return users;
}

bool UserMapper::deleteUsersByUserId(int userId)
{
    query.prepare("DELETE FROM user WHERE id=?");
    query.bindValue(0, userId);
    if(query.exec())
    {
        return true;
    }
    else {
        return false;
    }
}
