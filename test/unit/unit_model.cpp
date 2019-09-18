#include "unit_model.h"

UnitTestModel::UnitTestModel(){
    this->m = new Model(0, 100, 1);
}

UnitTestModel::~UnitTestModel(){

}

/*!
 * Unit test to check the method that sets the value of the start time attribute of the model class
 */

TEST_F(UnitTestModel, MethodSetInicial) {
    this->m->setInitial(3);
    EXPECT_EQ(this->m->getInitial(), 3);
}

/*!
 * Unit test to check the method that sets the value of the final time attribute of the model class
 */

TEST_F(UnitTestModel, MethodSetFinial) {
    this->m->setFinal(150);
    EXPECT_EQ(this->m->getFinal(), 150);
}

/*!
 * Unit test to check the method that sets the value of the step time attribute of the model class
 */

TEST_F(UnitTestModel, MethodSetStep) {
    this->m->setStep(2);
    EXPECT_EQ(this->m->getStep(), 2);
}

/*!
 * Unit test to check the method that add a new system to model class
 */

TEST_F(UnitTestModel, MethodAddSystem) {
    System *s = new System();
    int tam = this->m->SizeMySystems();
    this->m->Add(s);
    EXPECT_EQ(this->m->SizeMySystems(), tam+1);
}

/*!
 * Unit test to check the method that add a new ExpFlow to model class
 */

TEST_F(UnitTestModel, MethodAddExpFlow) {
    ExpFlow *f = new ExpFlow();
    int tam = this->m->SizeMyFlows();
    this->m->Add(f);
    EXPECT_EQ(this->m->SizeMyFlows(), tam+1);
}

/*!
 * Unit test to check the method that add a new LogFlow to model class
 */

TEST_F(UnitTestModel, MethodAddLogFlow) {
    LogFlow *f = new LogFlow();
    int tam = this->m->SizeMyFlows();
    this->m->Add(f);
    EXPECT_EQ(this->m->SizeMyFlows(), tam+1);
}
