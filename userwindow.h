#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "person.h"
#include "personmapper.h"
#include <QList>
#include "addpersondialog.h"
#include "personcontroller.h"
#include "departmentcontroller.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr, User *user = nullptr);
    ~UserWindow();
    void setUser(User *user);

private slots:

    void addPerson(Person person);

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_deleteButton_clicked();

    void on_addButton_clicked();

private:
    void tableViewDisplay(QList<Person> *persons);
    void tableViewReload();
    void createMenus();
    void setComboBox();
    QString findDepartmentNameBydepartmentId(int departmentId);
    int findDepartmentIdByDepartmentName(QString departmentName);
    Ui::UserWindow *ui;
    User *user;
    QList<Department> *departments;
    AddPersonDialog *addPersonDialog;
    PersonMapper personMapper;
    PersonController personController;
    DepartmentController departmentController;
};

#endif // USERWINDOW_H
