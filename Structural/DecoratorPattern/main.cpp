#include <QApplication>
#include <QtDebug>

#include "DynamicDecorator.h"
#include "StaticDecorator.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    qDebug()<<"Running dynamic decorator.........";
    CircleD c;
    ColoredShapeD cc("red", &c);
    std::cout << cc.str() << std::endl;
    // cannot call this:
    //cc.resize(1.2); // not part of ColoredShape


    qDebug()<<"Running static decorator.........";
    ColoredShapeS<CircleS> red_circle("red");
    std::cout << red_circle.str() << std::endl;
    // and this is legal
    red_circle.resize(1.5f);
    std::cout << red_circle.str() << std::endl;

    return 0;
}
