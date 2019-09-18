#include "flow.h"

/*!
 *
 * Flow class Constructor
 *
 */

Flow::Flow(string name)
{
    this->value = 0;
    this->name = name;
}

/*!
 *
 * Flow class destructor
 *
 */

Flow::~Flow()
{
    name.clear();
}

/*!
 *
 * Flow class Attribution operator
 * \return Pointer for object class
 *
 */

Flow &Flow::operator=(const Flow &f)
{
    if( &f != this ) {
        name.clear();
        this->name = f.name;

        delete this->in;
        delete this->out;

        this->in = f.in;
        this->out = f.out;
    }
    return *this;
}

/*!
 *
 * Flow class copy operator
 *
 */

Flow::Flow(Flow &f)
{
    name.clear();
    this->name = f.name;
    this->value = f.value;
}

/*!
 *
 * Method for get flow name
 * \return string with flow name
 *
 */

string Flow::getName() const
{
    return name;
}

/*!
 *
 * Method to set flow name
 * \param value for flow name
 *
 */

void Flow::setName(const string &value)
{
    name = value;
}

/*!
 *
 * Method to get flow value
 * \return Flow value
 *
 */

double Flow::getValue() const
{
    return value;
}

/*!
 *
 * Method to set flow value
 * \param value for New flow value
 *
 */

void Flow::setValue(double value)
{
    this->value = value;
}

/*!
 *
 * Method for connect two systems
 * \param s1 pointer for input system
 * \param s2 pointer for output system
 *
 */

void Flow::Conect(System *s1, System *s2)
{
    this->in = s1;
    this->out = s2;
}

/*!
 *
 * Method for get input system
 * \return Pointer for input system
 *
 */

System *Flow::getSystemIn()
{
    return this->in;
}

/*!
 *
 * Method for get output system
 * \return Pointer for input system
 *
 */

System *Flow::getSystemOut()
{
    return this->out;
}
