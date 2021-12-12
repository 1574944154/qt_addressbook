#ifndef DEPARTMENTCONTROLLER_H
#define DEPARTMENTCONTROLLER_H
#include "department.h"
#include "departmentmapper.h"

class DepartmentController
{
public:
    DepartmentController();
    QList<Department>* getDepartments();

private:
    DepartmentMapper departmentMapper;
};

#endif // DEPARTMENTCONTROLLER_H
