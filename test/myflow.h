#ifndef MYFLOW_H
#define MYFLOW_H


#include "../../src/model.h"

class ExpFlow: public Flow{
public:
    ExpFlow(string name = "") : Flow(name){}
    virtual double Execute();
};

class LogFlow: public Flow{
public:
    LogFlow(string name = "") : Flow(name){}
    virtual double Execute();
};


#endif // MYFLOW_H
