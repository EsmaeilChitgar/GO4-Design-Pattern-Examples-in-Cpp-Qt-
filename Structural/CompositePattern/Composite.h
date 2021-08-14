#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <QObject>
#include <QtDebug>

class IEmployee
{
public:
    virtual void ShowHappiness() = 0;
};

class Worker : public IEmployee
{
public:
    Worker(QString name, int happiness)
    {
        this->name = name;
        this->happiness = happiness;
    }

    void ShowHappiness()
    {
        qDebug()<<name << "showed happiness level of " << happiness;
    }

private:
    QString name;
    int happiness;
};

class Supervisor : public IEmployee
{
public:
    Supervisor(QString name, int happiness)
    {
        this->name = name;
        this->happiness = happiness;
    }

    void ShowHappiness()
    {
        qDebug()<<name << "showed happiness level of " << happiness;

        //show all the subordinate's happiness level
        foreach (IEmployee *i, subordinate)
        {
            i->ShowHappiness();
        }
    }

    void AddSubordinate(IEmployee *employee)
    {
        subordinate.append(employee);
    }

    bool removeSubordinate(IEmployee *employee)
    {
        return subordinate.removeOne(employee);
    }

private:
    QString name;
    int happiness;
    QList<IEmployee *> subordinate;
};

#endif // COMPOSITE_H
