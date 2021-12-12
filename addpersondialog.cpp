#include "addpersondialog.h"
#include "ui_addpersondialog.h"
#include "person.h"


AddPersonDialog::AddPersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonDialog)
{
    ui->setupUi(this);
}

AddPersonDialog::AddPersonDialog(QList<Department> *departments, QWidget *parent):
    QDialog(parent),
    ui(new Ui::AddPersonDialog),
    departments(departments)
{
    ui->setupUi(this);
}

AddPersonDialog::~AddPersonDialog()
{
    delete ui;
}


void AddPersonDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok)==(QPushButton *)button)
    {
        QString name = ui->nameEdit->text();
        QString phone = ui->phoneEdit->text();
        QString address = ui->addressEdit->text();
        QString departmentName = ui->departmentComboBox->currentText();
        int departmentId = findDepartmentByName(departmentName);
        Person person;
        person.setDepartmentId(departmentId);
        person.setName(name);
        person.setPhone(phone);
        person.setAddress(address);
        emit addPerson(person);
        this->close();
    }else{
        this->close();
    }
}

void AddPersonDialog::setDepartments(QList<Department> *departments)
{
    this->departments = departments;
}

void AddPersonDialog::setComboBox()
{
    for(auto department:*departments)
    {
        ui->departmentComboBox->addItem(department.getName());
    }
}

int AddPersonDialog::findDepartmentByName(QString name)
{
    for(auto department:*departments)
    {
        if(department.getName()==name) return department.getId();
    }
    return -1;
}
