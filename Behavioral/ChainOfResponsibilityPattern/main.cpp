#include <QApplication>
#include "ChainOfResponsibility.h"

//http://myprogrammingworks.blog.ir/post/%D8%A7%D9%84%DA%AF%D9%88%DB%8C-%D8%B7%D8%B1%D8%A7%D8%AD%DB%8C-Chain-of-Responsibility-%D8%AF%D8%B1-c-C-Chain-of-Responsibility-Design-Pattern

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)


    // Create instances for processing objects
    AnalyzeError analyzeError;
    FixError fixError;
    VerifyError verifyError;
    CloseError closeError;

    // Create the chain of responsibility
    analyzeError.SetSuccessor(&fixError);
    fixError.SetSuccessor(&verifyError);
    verifyError.SetSuccessor(&closeError);

    //(analyze-->Fix)       (Fix-->Verify)    (Verify-->close)

    // Issue command 1
    cout << "--------------- o/p for command 1 ----------------" << endl;
    ErrorReport errorReport1(ANALYZE);
    analyzeError.ProcessError(errorReport1);

    // Issue command 2
    cout << "--------------- o/p for command 2 ----------------" << endl;
    ErrorReport errorReport2(CLOSE);
    analyzeError.ProcessError(errorReport2);

    // Cleanup

    return 0;
}
