#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>

#include <QAbstractButton>

#include "user.h"

namespace Ui {
class AddUserDialog;
}

class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog(QWidget *parent = nullptr);
    ~AddUserDialog();
signals:
    void addUser(User user);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AddUserDialog *ui;
};

#endif // ADDUSERDIALOG_H
