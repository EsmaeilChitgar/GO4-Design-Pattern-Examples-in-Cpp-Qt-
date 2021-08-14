#ifndef BUILDER_H
#define BUILDER_H

#include <QObject>

class Product
{
public:
    Product(QString name)
    {
        mName = name;
    }

    QString name() const
    {
        return mName;
    }

    void setName(const QString &value)
    {
        mName = value;
    }

    QString screen() const
    {
        return mScreen;
    }

    void setScreen(const QString &value)
    {
        mScreen = value;
    }

    QString os() const
    {
        return mOS;
    }

    void setOS(const QString &value)
    {
        mOS = value;
    }

    QString toString() const
    {
        return QString("Name:%1,    OS:%2,    Screen:%3").arg(mName).arg(mOS).arg(mScreen);
    }

private:
    QString mName;
    QString mScreen;
    QString mOS;
};

class IBuilder
{
public:
    virtual void buildScreen() = 0;

    virtual void buildOS() = 0;
};

class ConcreteBuilder1 : public IBuilder
{
public:
    ConcreteBuilder1()
    {
        p = new Product("Android Cell Phone");
    }

    void buildScreen()
    {
        p->setScreen("Touch Screen 16 Inch!");
    }

    void buildOS()
    {
        p->setOS("Android 4.4");
    }

    Product *product()
    {
        return p;
    }

private:
    Product *p = nullptr;
};

class ConcreteBuilder2 : public IBuilder
{
public:
    ConcreteBuilder2()
    {
        p = new Product("Windows Phone");
    }

    void buildScreen()
    {
        p->setScreen("Touch Screen 32 Inch!");
    }

    void buildOS()
    {
        p->setOS("Windows Phone 2014");
    }

    Product *product()
    {
        return p;
    }

private:
     Product *p = nullptr;
};

class Director
{
public:
    void Construct(IBuilder *builder)
    {
        builder->buildScreen();
        builder->buildOS();
    }
};

#endif // BUILDER_H


