#include <iostream>
#include <QCoreApplication>

#include "SortTemplate.h"
#include "TestTemplate.h"

using namespace std;

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)


    //___________________________________________________________________________________________________
    cout<<"\n SortTemplate is running.......................\n";
    const int NUM = 10;
    int array[NUM];
    srand((unsigned)time(0));
    for (int i = 0; i < NUM; i++)
    {
        array[i] = rand() % 10+1;
        cout << array[i] << ' ';
    }

    cout << '\n';



    AbstractSort *sortObjects[] =
    {
        new SortUp, new SortDown
    };



    sortObjects[0]->sort(array, NUM);
    for (int u = 0; u < NUM; u++)
        cout << array[u] << ' ';

    cout << '\n';



    sortObjects[1]->sort(array, NUM);
    for (int d = 0; d < NUM; d++)
        cout << array[d] << ' ';

    cout << '\n';







    //___________________________________________________________________________________________________
    cout<<"\n TestTemplate is running.......................\n";
    Base *array2[] =
    {
        new One(), new Two()
    };

    for (int i = 0; i < 2; i++)
    {
        array2[i]->execute();
        cout << '\n';
    }










    //___________________________________________________________________________________________________
    system("pause");
}
