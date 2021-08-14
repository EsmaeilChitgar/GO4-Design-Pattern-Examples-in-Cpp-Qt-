#ifndef EMPLOYEEADAPTER_H
#define EMPLOYEEADAPTER_H

#include <QList>
#include <QtDebug>

//Adaptee class
class EmployeeDetail
{
  public:
    static void listEmployee(QList<QString> empList)
    {
        foreach (QString emp, empList)
        {
            qDebug()<<"emp"<<emp;
        }
    }
};


//The 'ITarget' interface
class IEmployee
{
public:
    virtual void printEmployee(QList<QString> empList) = 0;
};


//The 'Adapter' class
class EmployeeAdapter : public IEmployee
{
public:
    virtual void printEmployee(QList<QString> empList)
    {
        EmployeeDetail::listEmployee(empList);
    }
};

#endif // EMPLOYEEADAPTER_H
