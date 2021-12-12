#include "adduserdialog.h"
#include "ui_adduserdialog.h"

#include <QDialogButtonBox>

AddUserDialog::AddUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserDialog)
{
    ui->setupUi(this);
}

AddUserDialog::~AddUserDialog()
{
    delete ui;
}

void AddUserDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok)==(QPushButton *)button)
    {
        QString username = ui->usernameEdit->text();
        QString password = ui->passwordEdit->text();
        int type = 1;
        User user;
        user.setUsername(username);
        user.setPassword(password);
        user.setType(type);
        emit addUser(user);
        this->close();

    }else{
        this->close();
    }
}
