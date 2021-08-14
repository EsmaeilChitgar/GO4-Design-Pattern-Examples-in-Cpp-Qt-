#ifndef SUBJECTPROXY_H
#define SUBJECTPROXY_H

#include <QtDebug>

#include <iostream>
using namespace std;

class Subject
{
  public:
    virtual void execute() = 0;
};

class RealSubject: public Subject
{
  public:
    RealSubject(string s)
    {
        str = s;
    }

    /*virtual*/void execute()
    {
        cout <<"1111"<<__FUNCTION__<< str << endl;
//        qDebug()<<__FUNCTION__<< str.c_str();
    }

private:
    string str;
};

class ProxySubject: public Subject
{
  public:
    ProxySubject(string s)
    {
        int num = s.find_first_of(' ');
        first = s.substr(0, num);
        s = s.substr(num + 1);

        num = s.find_first_of(' ');
        second = s.substr(0, num);
        s = s.substr(num + 1);

        num = s.find_first_of(' ');
        third = s.substr(0, num);
        s = s.substr(num + 1);

        ptr = new RealSubject(s);
    }

    ~ProxySubject()
    {
        delete ptr;
    }

    RealSubject *operator->()
    {
        cout <<"2222"<<__FUNCTION__<< first << ' ' << second << ' '<<endl;

        return ptr;
    }

    /*virtual*/void execute()
    {
        cout <<"3333"<<__FUNCTION__<< first << ' ' << third << ' '<<endl;

        ptr->execute();
    }


private:
    string first, second, third;

    RealSubject *ptr;
};

#endif // SUBJECTPROXY_H
