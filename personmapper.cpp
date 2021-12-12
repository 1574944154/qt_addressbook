#include "personmapper.h"

PersonMapper::PersonMapper()
{

}


Person* PersonMapper::getPersonById(int id)
{
    Person *person = new Person();

    query.prepare("select * from person where id=?;");
    query.bindValue(0, id);
    query.exec();
    if(query.next())
    {
        QString name = query.value(query.record().indexOf("name")).toString();
        QString phone = query.value(query.record().indexOf("phone")).toString();
        QString address = query.value(query.record().indexOf("address")).toString();
        int userId = query.value(query.record().indexOf("userId")).toInt();
        int departmentId = query.value(query.record().indexOf("departmentId")).toInt();

        person->setId(id);
        person->setName(name);
        person->setPhone(phone);
        person->setAddress(address);
        person->setUserId(userId);
        person->setDepartmentId(departmentId);

        return person;
    }
    else
        return NULL;
}

QList<Person>* PersonMapper::getPersonsByUserId(int userId)
{
    QList<Person> *persons = new QList<Person>();
    query.prepare("SELECT * FROM person WHERE userId=?;");
    query.bindValue(0, userId);
    query.exec();
    while (query.next()) {
        Person *person = new Person();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString name = query.value(query.record().indexOf("name")).toString();
        QString phone = query.value(query.record().indexOf("phone")).toString();
        QString address = query.value(query.record().indexOf("address")).toString();
        int departmentId = query.value(query.record().indexOf("departmentId")).toInt();

        person->setId(id);
        person->setName(name);
        person->setPhone(phone);
        person->setAddress(address);
        person->setUserId(userId);
        person->setDepartmentId(departmentId);

        persons->append(*person);
    }
    return persons;
}

bool PersonMapper::insertPerson(Person person)
{
    query.prepare("INSERT INTO person(name, phone, address, userId, departmentId) VALUES (?, ?, ?, ?, ?)");
    query.bindValue(0, person.getName());
    query.bindValue(1, person.getPhone());
    query.bindValue(2, person.getAddress());
    query.bindValue(3, person.getUserId());
    query.bindValue(4, person.getDepartmentId());
    if(query.exec())
    {
        return true;
    }
    else
        return false;
}

QList<Person>* PersonMapper::getPersonsByUserIdAndDepartmentId(int userId, int departmentId)
{
    QList<Person> *persons = new QList<Person>();
    query.prepare("SELECT * FROM person WHERE userId=? and departmentId=?;");
    query.bindValue(0, userId);
    query.bindValue(1, departmentId);
    query.exec();
    while (query.next()) {
        Person *person = new Person();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString name = query.value(query.record().indexOf("name")).toString();
        QString phone = query.value(query.record().indexOf("phone")).toString();
        QString address = query.value(query.record().indexOf("address")).toString();

        person->setId(id);
        person->setName(name);
        person->setPhone(phone);
        person->setAddress(address);
        person->setUserId(userId);
        person->setDepartmentId(departmentId);

        persons->append(*person);
    }
    return persons;
}

QList<Person>* PersonMapper::getPersons()
{
    QList<Person> *persons = new QList<Person>();
    query.prepare("SELECT * FROM person;");
    query.exec();
    while (query.next()) {
        Person *person = new Person();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString name = query.value(query.record().indexOf("name")).toString();
        QString phone = query.value(query.record().indexOf("phone")).toString();
        QString address = query.value(query.record().indexOf("address")).toString();
        int userId = query.value(query.record().indexOf("userId")).toInt();
        int departmentId = query.value(query.record().indexOf("departmentId")).toInt();

        person->setId(id);
        person->setName(name);
        person->setPhone(phone);
        person->setAddress(address);
        person->setUserId(userId);
        person->setDepartmentId(departmentId);

        persons->append(*person);
    }
    return persons;
}

QList<Person>* PersonMapper::getPersonsByKeyWord(QString keyWord)
{
    QList<Person> *persons = new QList<Person>();
    query.prepare("SELECT * FROM person WHERE name like ? or phone like ? or address like ?;");
    query.bindValue(0, "%"+keyWord+"%");
    query.bindValue(1, "%"+keyWord+"%");
    query.bindValue(2, "%"+keyWord+"%");
    query.exec();
    while (query.next()) {
        Person *person = new Person();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString name = query.value(query.record().indexOf("name")).toString();
        QString phone = query.value(query.record().indexOf("phone")).toString();
        QString address = query.value(query.record().indexOf("address")).toString();
        int userId = query.value(query.record().indexOf("userId")).toInt();
        int departmentId = query.value(query.record().indexOf("departmentId")).toInt();

        person->setId(id);
        person->setName(name);
        person->setPhone(phone);
        person->setAddress(address);
        person->setUserId(userId);
        person->setDepartmentId(departmentId);

        persons->append(*person);
    }
    return persons;
}

QList<Person>* PersonMapper::getPersonsByUserIdAndKeyWord(int userId, QString keyWord)
{
    QList<Person> *persons = new QList<Person>();
    query.prepare("SELECT * FROM person WHERE userId=? and (name like ? or phone like ? or address like ?);");
    query.bindValue(0, userId);
    query.bindValue(1, "%"+keyWord+"%");
    query.bindValue(2, "%"+keyWord+"%");
    query.bindValue(3, "%"+keyWord+"%");
    query.exec();
    while (query.next()) {
        Person *person = new Person();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString name = query.value(query.record().indexOf("name")).toString();
        QString phone = query.value(query.record().indexOf("phone")).toString();
        QString address = query.value(query.record().indexOf("address")).toString();
        int userId = query.value(query.record().indexOf("userId")).toInt();
        int departmentId = query.value(query.record().indexOf("departmentId")).toInt();

        person->setId(id);
        person->setName(name);
        person->setPhone(phone);
        person->setAddress(address);
        person->setUserId(userId);
        person->setDepartmentId(departmentId);

        persons->append(*person);
    }
    return persons;
}

QList<Person>* PersonMapper::getPersonsByDepartmentId(int departmentId)
{
    QList<Person> *persons = new QList<Person>();
    query.prepare("SELECT * FROM person WHERE departmentId=?");
    query.bindValue(0, departmentId);
    query.exec();
    while (query.next()) {
        Person *person = new Person();
        int id = query.value(query.record().indexOf("id")).toInt();
        QString name = query.value(query.record().indexOf("name")).toString();
        QString phone = query.value(query.record().indexOf("phone")).toString();
        QString address = query.value(query.record().indexOf("address")).toString();
        int userId = query.value(query.record().indexOf("userId")).toInt();

        person->setId(id);
        person->setName(name);
        person->setPhone(phone);
        person->setAddress(address);
        person->setUserId(userId);
        person->setDepartmentId(departmentId);

        persons->append(*person);
    }
    return persons;
}

bool PersonMapper::deletePersonById(int id)
{
    query.prepare("DELETE FROM person WHERE id=?");
    query.bindValue(0, id);
    if(query.exec())
    {
        return true;
    }
    else {
        return false;
    }
}
