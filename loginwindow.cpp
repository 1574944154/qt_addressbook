#include "loginwindow.h"
#include "userwindow.h"
#include "adminwindow.h"


#include <ui_loginwindow.h>

#include <QMessageBox>
#include <QtDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{

    ui->setupUi(this);

}

LoginWindow::~LoginWindow()
{
    database.close();
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    User *user = userService.login(username, password);
    if(user==NULL)
    {
        QMessageBox::information(this, "提示", "登录失败");
        return;
    }else{
        QMessageBox::information(this, "提示", "登录成功");
        int type = user->getType();
        if(type==0)
        {
            qDebug() << "弹出管理员用户界面";
            this->hide();
            adminWindow = new AdminWindow(this);
            adminWindow->show();
        }else{
            qDebug() << "弹出普通用户界面";
            this->hide();
            userWindow = new UserWindow(this, user);
            userWindow->show();
        }

    }
}


void LoginWindow::openDatabase(QString databaseName)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databaseName);
    if(!database.open())
    {
        qDebug() << "error: fail to open database.";
        exit(1);
    }else {
        qDebug() << "success to open database.";
    }
}
