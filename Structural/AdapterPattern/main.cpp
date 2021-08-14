#include <QApplication>

#include "PlugAdapter.h"
#include "EmployeeAdapter.h"

//https://www.codeproject.com/Tips/595716/Adapter-Design-Pattern-in-Cplusplus

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)


    qDebug()<<"Plug adapter played...";
    SwitchBoard *mySwitchBoard = new SwitchBoard; // Adaptee
    //Target = Adapter(Adaptee)
    AbstractPlug *adapter = new Adapter(mySwitchBoard);
    adapter->RoundPin();
    adapter->PinCount();



    qDebug()<<"Employee adapter played...";
    QList<QString> empList;
    empList.append("Ali");
    empList.append("Hasan");
    empList.append("Hossein");

    IEmployee *emp = new EmployeeAdapter;
    emp->printEmployee(empList);

    return 0;
}
