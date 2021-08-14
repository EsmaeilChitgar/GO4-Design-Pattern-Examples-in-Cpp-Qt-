#include "Singleton.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Singleton *obj;
    obj = Singleton::instance();

    Q_UNUSED(obj);

    return 0;
}
