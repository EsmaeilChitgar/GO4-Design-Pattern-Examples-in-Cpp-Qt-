#ifndef ABSTRACTFACTORY2_H
#define ABSTRACTFACTORY2_H

#include <QtDebug>

namespace AbstractFactory2
{

class Widget
{
public:
    virtual void draw() = 0;
};



class LinuxButton : public Widget
{
public:
    void draw()
    {
        qDebug() <<"LinuxButton";
    }
};

class LinuxMenu : public Widget
{
public:
    void draw()
    {
        qDebug() <<"LinuxMenu";
    }
};



class WindowsButton : public Widget
{
public:
    void draw()
    {
        qDebug() <<"WindowsButton";
    }
};

class WindowsMenu : public Widget
{
public:
    void draw()
    {
        qDebug() <<"WindowsMenu";
    }
};



class Factory
{
public:
    virtual Widget *create_button() = 0;
    virtual Widget *create_menu() = 0;
};



class LinuxFactory : public Factory
{
public:
    Widget *create_button()
    {
        return new LinuxButton;
    }

    Widget *create_menu()
    {
        return new LinuxMenu;
    }
};

class WindowsFactory : public Factory
{
public:
    Widget *create_button()
    {
        return new WindowsButton;
    }

    Widget *create_menu()
    {
        return new WindowsMenu;
    }
};



class Client
{
private:
    Factory *mFactory;

public:
    Client(Factory *f)
    {
        mFactory = f;
    }

    void draw()
    {
        Widget *w = mFactory->create_button();
        w->draw();

        display_window_one();

        display_window_two();
    }

    void display_window_one()
    {
        Widget *w[] =
        {
            mFactory->create_button(),
            mFactory->create_menu()
        };

        w[0]->draw();
        w[1]->draw();
    }

    void display_window_two()
    {
        Widget *w[] =
        {
            mFactory->create_menu(),
            mFactory->create_button()
        };

        w[0]->draw();
        w[1]->draw();
    }
};

}

#endif // ABSTRACTFACTORY2_H
