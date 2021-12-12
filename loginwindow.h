#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <usercontroller.h>

#include "userwindow.h"
#include "usermapper.h"
#include "adminwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    bool login(QString, QString);
private slots:

    void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;
    UserController userController;
    UserWindow *userWindow;
    AdminWindow *adminWindow;

    UserMapper userMapper;
};

#endif // LOGINWINDOW_H
