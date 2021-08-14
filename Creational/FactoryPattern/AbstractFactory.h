#ifndef ABSTRACTFACTORY2_H
#define ABSTRACTFACTORY2_H

#include <QtDebug>

namespace AbstractFactory
{

class Mobile
{
public:
    virtual QString Camera() = 0;
    virtual QString KeyBoard() = 0;

    void PrintSpecs()
    {
        qDebug() <<__FUNCTION__ << "Camera:" <<Camera()<< "KeyBoard:" <<KeyBoard();
    }
};

class LowEndMobile : public Mobile
{
public:
    ~LowEndMobile(){}

    QString Camera() { return "2 MegaPixel"; }

    QString KeyBoard() { return "ITU-T"; }
};

class HighEndMobile : public Mobile
{
public:
    ~HighEndMobile(){}

    QString Camera() { return "5 MegaPixel"; }

    QString KeyBoard() { return "Qwerty"; }
};


class MobileFactory
{
public:
    Mobile *GetMobile(QString type)
    {
        if (type == "Low-End")
            return new LowEndMobile();

        if (type == "High-End")
            return new HighEndMobile();

        return nullptr;
    }
};

}

#endif // ABSTRACTFACTORY2_H
