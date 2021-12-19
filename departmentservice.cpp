#include "departmentservice.h"

DepartmentService::DepartmentService()
{

}

QList<Department>* DepartmentService::getDepartments()
{
    return departmentMapper.getDepartments();
}
