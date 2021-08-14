#include <QApplication>

#include "State.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    void(Machine:: *ptrs[])() =
     {
       Machine::off, Machine::on
     };

     Machine fsm;
     int num;
     while (1)
     {
       cout << "Enter 0/1: ";
       cin >> num;
       (fsm.*ptrs[num])();
     }

    return 0;
}
