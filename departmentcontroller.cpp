#include "departmentcontroller.h"

DepartmentController::DepartmentController()
{

}

QList<Department>* DepartmentController::getDepartments()
{
    return departmentMapper.getDepartments();
}
