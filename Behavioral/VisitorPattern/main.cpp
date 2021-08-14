#include <QApplication>

#include "TemplateVisitor.h"
#include "ColorVisitor.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    cout<<"\nTemplateVisitor is running..................................\n";
    //1..................................................................
    list<shared_ptr<DataStructIntf>> DataStructureList1;
    DataStructureList1.push_back(make_shared<ConcreteDataStruct1>());
    DataStructureList1.push_back(make_shared<ConcreteDataStruct2>());

    shared_ptr<VisitorAlgorithmIntf> visitor1 = make_shared<ConcreteVisitorAlgorithm1>();

    for (auto ds : DataStructureList1)
    {
        ds->accept(visitor1);
    }

    //2..................................................................
    list<shared_ptr<DataStructIntf>> elementList2;
    elementList2.push_back(make_shared<ConcreteDataStruct1>());
    elementList2.push_back(make_shared<ConcreteDataStruct2>());
    shared_ptr<VisitorAlgorithmIntf> visitor2 = make_shared<ConcreteVisitorAlgorithm2>();

    for (auto ds : elementList2)
    {
        ds->accept(visitor2);
    }













    cout<<"\nColorVisitor is running..................................\n";
    Color *set[] =
    {
        new Red, new Blu, new Blu, new Red, new Red, 0
    };

    CountVisitor count_operation;
    CallVisitor call_operation;

    for (int i = 0; set[i]; i++)
    {
        set[i]->accept(&count_operation);
        set[i]->accept(&call_operation);
    }

    count_operation.report_num();

    return 0;
}
