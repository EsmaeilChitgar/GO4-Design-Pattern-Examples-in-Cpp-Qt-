#include <QCoreApplication>

#include "FamilyVehicleStrategy.h"
#include "SortStrategy.h"

using namespace std;

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    cout<<"\n Family And Vehicle Strategy is playing\n";
    Family *fam = new Father();
    fam->display();
    fam->setVehicle(new FordFigo());
    fam->driveVehicle();

    fam = new Daughter();
    fam->display();
    fam->setVehicle(new HondaActiva());
    fam->driveVehicle();



    cout<<"\n Sort Strategy is playing\n";
    Merge merge;
    Quick quick;
    Heap heap;

    Sequential sequential;
    BinaryTree binaryTree;
    HashTable hashTable;

    Collection colA;
    colA.set_sort(&merge);
    colA.sort();

    Collection colB;
    colB.set_search(&binaryTree);
    colB.search();

    return 0;
}
