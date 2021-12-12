#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <QString>

class Department
{
public:
    Department();
    int getId();
    QString getName();

    void setId(int id);
    void setName(QString name);
private:
    int id;
    QString name;
};

#endif // DEPARTMENT_H
