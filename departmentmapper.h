#ifndef DEPARTMENTMAPPER_H
#define DEPARTMENTMAPPER_H
#include <QtSql>
#include <QList>
#include "department.h"

class DepartmentMapper
{
public:
    DepartmentMapper();
    QList<Department>* getDepartments();
private:
    QSqlQuery query;
};

#endif // DEPARTMENTMAPPER_H
