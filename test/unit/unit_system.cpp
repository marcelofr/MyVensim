#include "unit_system.h"

//---------------------UnitTestSystem

UnitTestSystem::UnitTestSystem()
{
    this->s = new System();
}

UnitTestSystem::~UnitTestSystem()
{

}

/*!
 * Unit test to check the method that sets the system value
 */

TEST_F(UnitTestSystem, MethodSetValue) {
    this->s->setValue(4);
    EXPECT_EQ(this->s->getValue(), 4);
}

/*!
 * Unit test to check the method that sets the system name
 */

TEST_F(UnitTestSystem, MethodSetName) {
    string newname = "New name";
    this->s->setName(newname);
    EXPECT_EQ(this->s->getName(), newname);
}
