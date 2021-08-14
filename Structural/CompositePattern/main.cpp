#include <QApplication>

#include "Composite.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Worker *w_Tom = new Worker("Worker Tom", 5);
    Supervisor *sv_Mary = new Supervisor("Supervisor Mary", 6);
    Supervisor *sv_Jerry = new Supervisor("Supervisor Jerry", 7);
    Supervisor *sv_Bob = new Supervisor("Supervisor Bob", 9);
    Worker *w_Jimmy = new Worker("Worker Jimmy", 8);

    /*
                   Jerry
        |-----------------------|
            Mary         Bob
          |------|    |-------|
            Tom         Jimmy
    */


    //set up the relationships
    sv_Mary->AddSubordinate(w_Tom); //Tom works for Mary
    sv_Jerry->AddSubordinate(sv_Mary); //Mary works for Jerry
    sv_Jerry->AddSubordinate(sv_Bob); //Bob works for Jerry
    sv_Bob->AddSubordinate(w_Jimmy); //Jimmy works for Bob

    //Jerry shows his happiness and asks everyone else to do the same
    sv_Jerry->ShowHappiness();

    return 0;
}


