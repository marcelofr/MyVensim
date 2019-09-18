#ifndef FLOW_H
#define FLOW_H

#include <stdio.h>
#include "system.h"

/*!
 *
 * \class Flow
 *
 * \brief Class to define a flow in the model
 *
 */

class Flow
{
protected:
    double value; /**< Current flow value*/
    System *in; /**< Pointer for input flow system*/
    System *out;  /**< Pointer for output flow system*/
    string name;  /**< Flow name*/
public:
    Flow(string name = "");
    virtual ~Flow();
    Flow& operator=(const Flow&);
    Flow( Flow& );
    double getValue() const;
    void setValue(double value);
    /*!
     * This method needs to be implemented to define flow execution
     * \return It returns the value that will be added / decremented to the flow.
     */
    virtual double Execute() = 0;
    void Conect(System *s1, System *s2);
    System *getSystemIn();
    System *getSystemOut();
    string getName() const;
    void setName(const string &value);
};

#endif // FLOW_H
