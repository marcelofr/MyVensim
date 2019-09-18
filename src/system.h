#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

/*!
 * \class Flow
 *
 * \brief Class to define a system in the model
 *
 */

class System
{
protected:
    double value;
    double tempValue;
    string name;
public:
    System(double v=0.0, string name="");
    virtual ~System();
    double getValue();
    void setValue(double value);
    string getName() const;
    void setName(const string &name);
    System& operator=(const System&);
    System( System& );
    double getTempValue() const;
    void setTempValue(double value);
};

#endif // SYSTEM_H
