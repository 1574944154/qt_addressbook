#include "adminwindow.h"
#include "ui_adminwindow.h"

#include <QStandardItemModel>
#include <QMessageBox>

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    users = userService.getUsers();
    tableViewDisplay();
}

AdminWindow::~AdminWindow()
{
    delete users;
    delete ui;
}

void AdminWindow::tableViewDisplay()
{
    users = userService.getUsers();
    QStandardItemModel *model = new QStandardItemModel(ui->tableView);
    model->setColumnCount(3);
    model->setHeaderData(0, Qt::Horizontal, "id");
    model->setHeaderData(1, Qt::Horizontal, "用户名");
    model->setHeaderData(2, Qt::Horizontal, "密码");

    for(int i=0;i<users->size();i++)
    {
        model->setItem(i, 0, new QStandardItem(QString::number((*users)[i].getId())));
        model->setItem(i, 1, new QStandardItem((*users)[i].getUsername()));
        model->setItem(i, 2, new QStandardItem((*users)[i].getPassword()));
    }

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
}

void AdminWindow::on_pushButton_2_clicked()
{
    QModelIndex ci = ui->tableView->currentIndex();
    QAbstractItemModel *model = ui->tableView->model();
    int row = ci.row();
    if(row==-1)
    {
        QMessageBox::information(this, "错误", "没有选择删除的对象");
    }else
    {
        int id = model->index(row, 0, QModelIndex()).data().toInt();
        bool res = userService.deleteUserById(id);
        if(res){
            QMessageBox::information(this, "提示", "删除成功");
            tableViewDisplay();
        }else{
            QMessageBox::information(this, "提示", "删除失败");
        }
    }
}

void AdminWindow::addUser(User user)
{
    if(userService.addUser(user))
    {
        QMessageBox::information(this, "提示", "添加成功");
        tableViewDisplay();
    }
    else{
        QMessageBox::information(this, "警告", "添加失败");
    }
}

void AdminWindow::on_pushButton_clicked()
{
    addUserDialog = new AddUserDialog(this);
    connect(addUserDialog, &AddUserDialog::addUser, this, &AdminWindow::addUser);
    addUserDialog->show();
}
