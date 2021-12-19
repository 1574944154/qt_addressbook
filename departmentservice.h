#ifndef DEPARTMENTCONTROLLER_H
#define DEPARTMENTCONTROLLER_H
#include "department.h"
#include "departmentmapper.h"

class DepartmentService
{
public:
    DepartmentService();
    QList<Department>* getDepartments();

private:
    DepartmentMapper departmentMapper;
};

#endif // DEPARTMENTCONTROLLER_H
