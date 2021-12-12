#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDebug>

class Person
{
public:
    Person();
    int getId();
    QString getName();
    QString getPhone();
    QString getAddress();
    int getUserId();
    int getDepartmentId();

    void setId(int);
    void setName(QString name);
    void setPhone(QString phone);
    void setAddress(QString address);
    void setUserId(int userId);
    void setDepartmentId(int departmentId);

private:
    int id;
    QString name;
    QString phone;
    QString address;
    int userId;
    int departmentId;
};

QDebug operator<<(QDebug debug, Person &person);

#endif // PERSON_H
