#include "system.h"

/*!
 *
 * System class Constructor
 *
 */

System::System(double v, string n)
{
    this->value = v;
    this->name = n;
    this->tempValue = v;
}

/*!
 *
 * System class destructor
 *
 */

System::~System(){
    this->name.clear();
}

/*!
 *
 * Method to get system value
 * \return System value
 *
 */

double System::getValue()
{
    return value;
}

/*!
 *
 * Method to set system value
 * \param value for new system value
 *
 */

void System::setValue(double value)
{
    this->value = value;
}

/*!
 *
 * Method for get system name
 * \return string with system name
 *
 */

string System::getName() const
{
    return name;
}

/*!
 *
 * Method to set system name
 * \param name set new value for system name
 *
 */

void System::setName(const string &name)
{
    this->name = name;
}

/*!
 *
 * Model class Attribution operator
 * \return Pointer for object class
 *
 */

System &System::operator=(const System &s)
{
    if( &s != this ) {
        name.clear();
        this->name = s.name;
    }
    return *this;
}

/*!
 *
 * Model class copy operator
 *
 */

System::System(System &s)
{
    name.clear();
    this->name = s.name;
    this->value = s.value;
}

/*!
 *
 * Method to get the temporary value used during the model execution
 * \return  Temporary system value
 *
 */

double System::getTempValue() const
{
    return tempValue;
}

/*!
 *
 * Method to save the temporary value used during the model execution
 * \param value for new temporary system value
 *
 */

void System::setTempValue(double value)
{
    tempValue = value;
}
