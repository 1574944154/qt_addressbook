#include "userwindow.h"
#include "ui_userwindow.h"

#include <QStandardItemModel>
#include <QMessageBox>

#include <QDebug>

#include <QModelIndex>


UserWindow::UserWindow(QWidget *parent, User *user) :
    QMainWindow(parent),
    ui(new Ui::UserWindow),
    user(user)
{
    ui->setupUi(this);
    departments = departmentController.getDepartments();
    createMenus();
    tableViewDisplay(personController.getPersonsByUserId(user->getId()));
    setComboBox();
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::setUser(User *user)
{
    this->user = user;
}

void UserWindow::createMenus()
{
    menuBar()->addMenu(tr("文件"));
    menuBar()->addMenu(tr("工具"));
}

void UserWindow::tableViewDisplay(QList<Person> *persons)
{
    QStandardItemModel *model = new QStandardItemModel(this);

    model->setColumnCount(5);
    model->setHeaderData(0, Qt::Horizontal, "序号");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "电话");
    model->setHeaderData(3, Qt::Horizontal, "地址");
    model->setHeaderData(4, Qt::Horizontal, "部门");

    for(int i=0;i<persons->size();i++)
    {
        model->setItem(i, 0, new QStandardItem(QString::number((*persons)[i].getId())));
        model->setItem(i, 1, new QStandardItem((*persons)[i].getName()));
        model->setItem(i, 2, new QStandardItem((*persons)[i].getPhone()));
        model->setItem(i, 3, new QStandardItem((*persons)[i].getAddress()));
        int departmentId = (*persons)[i].getDepartmentId();
        QString departmentName = findDepartmentNameBydepartmentId(departmentId);
        model->setItem(i, 4, new QStandardItem(departmentName));

    }
    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
}

void UserWindow::on_pushButton_clicked()
{
    QString keyWord = ui->searchEdit->text();
    if(keyWord=="")
    {
        QMessageBox::information(this, "警告", "关键字为空!");
    }
    else
    {
        QList<Person> *persons = personMapper.getPersonsByUserIdAndKeyWord(user->getId(), keyWord);
        tableViewDisplay(persons);
    }
}

void UserWindow::on_comboBox_currentIndexChanged(const QString &departmentName)
{
    if(departmentName=="ALL") {
        tableViewDisplay(personController.getPersonsByUserId(user->getId()));
    }else{
        int departmentId  = findDepartmentIdByDepartmentName(departmentName);
        tableViewDisplay(personController.getPersonsByUserIdAndDepartmentId(user->getId(), departmentId));
    }
}


void UserWindow::on_deleteButton_clicked()
{
    QModelIndex ci = ui->tableView->currentIndex();
    QAbstractItemModel * model = ui->tableView->model();
    qDebug() << ci;
    int row = ci.row();
    if(row==-1)
    {
        QMessageBox::information(this, "错误", "没有选择删除的对象");
    }else{
        int id = model->index(row, 0, QModelIndex()).data().toInt();
        qDebug() << id;
        bool res = personController.deletePersonById(id);
        if(res){
            QMessageBox::information(this, "提示", "删除成功");
            tableViewReload();
        }else{
            QMessageBox::information(this, "提示", "删除失败");
        }
    }
}

void UserWindow::tableViewReload()
{
    tableViewDisplay(personController.getPersons());
}

void UserWindow::on_addButton_clicked()
{
    addPersonDialog = new AddPersonDialog(this);
    connect(addPersonDialog, &AddPersonDialog::addPerson, this, &UserWindow::addPerson);
    QList<Department> *departments = departmentController.getDepartments();
    addPersonDialog->setDepartments(departments);
    addPersonDialog->setComboBox();
    addPersonDialog->show();
}

void UserWindow::addPerson(Person person)
{
    person.setUserId(user->getId());
    bool res = personMapper.insertPerson(person);
    if(!res)
    {
        QMessageBox::information(this, "警告", "添加失败");
        return;
    }else{
        QMessageBox::information(this, "提示", "添加成功");
        tableViewDisplay(personMapper.getPersonsByUserId(user->getId()));
    }
}

void UserWindow::setComboBox()
{
    ui->comboBox->addItem("ALL");
    for(auto department:*departments)
    {
        ui->comboBox->addItem(department.getName());
    }
}

QString UserWindow::findDepartmentNameBydepartmentId(int departmentId)
{
    for(auto department:*departments)
    {
        if(department.getId()==departmentId)
        {
            return department.getName();
        }
    }
    return "";
}

int UserWindow::findDepartmentIdByDepartmentName(QString departmentName)
{
    for(auto department:*departments)
    {
        if(department.getName()==departmentName) return department.getId();
    }
    return -1;
}
