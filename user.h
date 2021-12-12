#ifndef USER_H
#define USER_H
#include <QString>
#include <iostream>

class User
{
public:
    User();
    User(QString username, QString password, int type);
    int getId();
    QString getUsername();
    QString getPassword();
    int getType();

    void setUsername(QString username);
    void setPassword(QString password);
    void setType(int type);
    void setId(int id);
private:
    int id;
    QString username;
    QString password;
    int type;
};


#endif // USER_H
