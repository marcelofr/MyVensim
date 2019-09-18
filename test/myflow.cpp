#include "myflow.h"

double ExpFlow::Execute() {
    double var;
    var = this->getSystemIn()->getValue()*0.01;
    this->setValue(var);
    //var = this->getValue()*0.01;
    return var;
};


double LogFlow::Execute() {
    double var;
    var = 0.01*this->getSystemIn()->getValue()*(1-this->getSystemIn()->getValue()/70);
    this->setValue(var);
    return (-1)*var;
};
