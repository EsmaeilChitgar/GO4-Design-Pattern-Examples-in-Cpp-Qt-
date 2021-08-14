#include <QApplication>
#include <QtDebug>

#include "Builder.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Director *d = new Director();
    ConcreteBuilder1 *cb1 = new ConcreteBuilder1();
    d->Construct(cb1);
    qDebug()<<cb1->product()->toString();

    return 0;
}
