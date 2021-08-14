#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtDebug>

class Singleton
{
public:
    static Singleton* mInstance;

public:
    static Singleton *instance()
    {
        if (mInstance == NULL)
        {
            mInstance = new Singleton();
        }

        return mInstance;
    }

private:
    Singleton()
    {
        qDebug() <<"In construtor ...";
    }

};

Singleton* Singleton::mInstance = NULL;


#endif // SINGLETON_H
