#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <userservice.h>
#include <QtSql>

#include "userwindow.h"
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
    void openDatabase(QString databaseName);
    QSqlDatabase database;
    Ui::LoginWindow *ui;
    UserService userService;
    UserWindow *userWindow;
    AdminWindow *adminWindow;
};

#endif // LOGINWINDOW_H
