#include "unit_flow.h"

//---------------------UnitTestFlow

UnitTestFlow::UnitTestFlow()
{
    this->ef = new ExpFlow();
}

UnitTestFlow::~UnitTestFlow()
{

}

/*!
 * Unit test to check the method that sets the flow value
 */

TEST_F(UnitTestFlow, MethodSetValue) {
    this->ef->setValue(4);
    EXPECT_EQ(this->ef->getValue(), 4);
}


/*!
 * Unit test to check the method that connect two systems in flow class
 */

TEST_F(UnitTestFlow, MethodConect) {

    System *s1 = new System();
    System *s2 = new System();
    this->ef->Conect(s1, s2);
    EXPECT_EQ(this->ef->getSystemIn(), s1);
    EXPECT_EQ(this->ef->getSystemOut(), s2);
}

/*!
 * Unit test to check the method that sets the flow name
 */

TEST_F(UnitTestFlow, MethodSetName) {
    this->ef->setName("New name");
    EXPECT_EQ(this->ef->getName(), "New name");
}
