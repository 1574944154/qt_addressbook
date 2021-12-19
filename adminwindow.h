#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "userwindow.h"
#include "user.h"
#include "userservice.h"
#include "adduserdialog.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void addUser(User user);

private:

    void tableViewDisplay();
    AddUserDialog *addUserDialog;
    Ui::AdminWindow *ui;
    QList<User> *users;

    UserService userService;

};

#endif // ADMINWINDOW_H
