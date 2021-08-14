#include <QApplication>

#include "Observer.h"
#include "Observer2.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)


    cout<<"\nPlay Observer1.....................................................";
    Observer1ns::SensorSystem ss;


    Observer1ns::Gates g;
    ss.attach(&g);

    Observer1ns::Lighting l;
    ss.attach(&l);

    Observer1ns::Surveillance s;
    ss.attach(&s);


    ss.soundTheAlarm();





    cout<<"\nPlay Observer2.....................................................";
    Observer2ns::Subject subj;
    Observer2ns::DivObserver divObs1(&subj, 4); // 7. Client configures the number and
    Observer2ns::DivObserver divObs2(&subj, 3); //    type of Observers
    Observer2ns::ModObserver modObs3(&subj, 3);
    subj.setVal(14);

    return 0;
}
