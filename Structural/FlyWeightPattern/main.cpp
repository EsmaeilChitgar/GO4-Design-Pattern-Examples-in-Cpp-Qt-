#include <QApplication>

#include "FlyWeight.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    for (int i = 0; i < Factory::X; ++i)
    {
        for (int j = 0; j < Factory::Y; ++j)
        {
            Factory::get_fly(i)->report(j);
        }

        cout << '\n';
    }

    Factory::clean_up();

    return 0;
}
