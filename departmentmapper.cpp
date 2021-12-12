#include "departmentmapper.h"

DepartmentMapper::DepartmentMapper()
{

}


QList<Department>* DepartmentMapper::getDepartments()
{
    QList<Department> *departments = new QList<Department>();
    query.prepare("SELECT * FROM department;");
    query.exec();
    while (query.next()) {
        Department *department = new Department();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString name = query.value(query.record().indexOf("name")).toString();

        department->setId(id);
        department->setName(name);

        departments->append(*department);
    }
    return departments;
}
