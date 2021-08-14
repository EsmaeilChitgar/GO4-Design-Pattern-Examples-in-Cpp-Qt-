#include <QApplication>

#include "DriveProxy.h"
#include "SubjectProxy.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    cout<<"Car proxy is running....................."<<endl;
    ICar* car = new ProxyCar(16);
    car->DriveCar();
    delete car;

    car = new ProxyCar(25);
    car->DriveCar();
    delete car;



    cout<<endl<<"Subject proxy is running....................."<<endl;
    ProxySubject obj(string("the quick brown fox jumped over the dog"));
    obj->execute();
    obj.execute();

    return 0;
}
