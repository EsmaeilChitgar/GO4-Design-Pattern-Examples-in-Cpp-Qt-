#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H

#include <iostream>
using namespace std;


// STATES
enum ErrorStates { ANALYZE = 0, FIX, VERIFY, CLOSE };


// Command Class
class ErrorReport
{
public:
  ErrorReport(ErrorStates state) { this->state = state; }
  ErrorStates GetState() { return state; }
  void SetState(ErrorStates state) { this->state = state; }

private:
  ErrorStates state;
};


// General base class for all processing objects
class Error
{
public:
  virtual ~Error() {}

  Error(ErrorStates aState) { state = aState; }

  void SetSuccessor(Error *error) { this->successor = error; }

  virtual void ProcessError(ErrorReport &report) = 0;

protected:
  ErrorStates state;
  Error *successor;
};


// Processing object class 1 for state ANALYZE
class AnalyzeError : public Error
{

  public:
    AnalyzeError() : Error(ANALYZE) {}
    ~AnalyzeError() {}
    void ProcessError(ErrorReport &report)
    {
    if (report.GetState() == ANALYZE) {
        cout << "AnalyzeError::Handled the command to analyze the error ..."
         << endl;
    }
    else {
        cout << "AnalyzeError::Passing to my successor ..." << endl;
        successor->ProcessError(report);
    }
    }
};


// Processing object class 2 for state  FIX
class FixError : public Error
{
  public:
    FixError() : Error(FIX) {}
    ~FixError() {}
    void ProcessError(ErrorReport &report)
    {
    if (report.GetState() == FIX) {
        cout << "FixError::Handled the command to fix the error ..."
         << endl;
    }
    else {
        cout << "FixError::Passing to my successor ..." << endl;
        successor->ProcessError(report);
    }
    }
};


// Processing object class 3 for state VERIFY
class VerifyError : public Error
{
  public:
    VerifyError() : Error(VERIFY) {}
    ~VerifyError() {}
    void ProcessError(ErrorReport &report)
    {
    if (report.GetState() == VERIFY) {
        cout << "VerifyError::Handled the command to verify the error ..."
         << endl;
    }
    else {
        cout << "VerifyError::Passing to my successor ..." << endl;
        successor->ProcessError(report);
    }
    }
};


// Processing object class 4 for state CLOSE
class CloseError : public Error
{
  public:
    CloseError() : Error(CLOSE) {}
    ~CloseError() {}
    void ProcessError(ErrorReport &report)
    {
    if (report.GetState() == CLOSE) {
        cout << "CloseError::Handled the command to close the error ..."
         << endl;
    }
    else {
        cout << "VerifyError::No successor ... ignore" << endl;
        cout << "No action required ..." << endl;
    }
    }
};


#endif // CHAINOFRESPONSIBILITY_H
