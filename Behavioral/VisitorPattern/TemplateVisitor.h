#ifndef TEMPLATEVISITOR_H
#define TEMPLATEVISITOR_H

#include <iostream>
#include <list>
#include <memory>

using namespace std;

//Forwards
class VisitorAlgorithmIntf;


//Each Data_Structure/Element has an accept() function which invokes Algorithm
//Each Algorithm has a visit() function which invokes a Data_Structure/Element


//Abstract interface for Element objects (Data_Structure/Element)
class DataStructIntf
{
  public:
    virtual ~DataStructIntf() {}
    virtual string name() = 0;
    virtual void accept(shared_ptr<VisitorAlgorithmIntf> object) = 0;
};

//Abstract interface for Visitor objects (Algorithm)
class VisitorAlgorithmIntf
{
  public:
    virtual ~VisitorAlgorithmIntf() {}
    virtual void visit(DataStructIntf *object) = 0;
};




//Concrete element object
class ConcreteDataStruct1 : public DataStructIntf
{
  public:
    string name() { return "ConcreteDataStruct1"; }

    void accept(shared_ptr<VisitorAlgorithmIntf> object)
    {
        object->visit(this);
    }
};

//Concrete element object
class ConcreteDataStruct2 : public DataStructIntf
{
  public:
    string name() { return "ConcreteDataStruct2"; }

    void accept(shared_ptr<VisitorAlgorithmIntf> object)
    {
        object->visit(this);
    }
};




//Visitor logic 1
class ConcreteVisitorAlgorithm1 : public VisitorAlgorithmIntf
{
  public:
    void visit(DataStructIntf *object)
    {
        cout << "Visited " << object->name() << " using ConcreteAlgorithm1." << endl;
    }
};

//Visitor logic 2
class ConcreteVisitorAlgorithm2 : public VisitorAlgorithmIntf
{
  public:
    void visit(DataStructIntf *object)
    {
        cout << "Visited " << object->name() << " using ConcreteAlgorithm2." << endl;
    }
};

#endif // TEMPLATEVISITOR_H
