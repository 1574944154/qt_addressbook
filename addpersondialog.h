#ifndef ADDPERSONDIALOG_H
#define ADDPERSONDIALOG_H

#include <QDialog>
#include <QList>
#include <QAbstractButton>
#include "person.h"
#include "department.h"

namespace Ui {
class AddPersonDialog;
}

class AddPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonDialog(QWidget *parent = nullptr);
    AddPersonDialog(QList<Department> *department, QWidget *parent = nullptr);
    ~AddPersonDialog();
    void setDepartments(QList<Department> *departments);
    void setComboBox();
signals:
    void addPerson(Person person);
private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    int findDepartmentByName(QString name);
    Ui::AddPersonDialog *ui;
    Person person;
    QList<Department> *departments;
};

#endif // ADDPERSONDIALOG_H
