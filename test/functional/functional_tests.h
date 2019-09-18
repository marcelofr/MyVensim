#ifndef FUNCTIONAL_TESTS_H
#define FUNCTIONAL_TESTS_H


#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/model.h"
#include "../myflow.h"

const static double EPSILON = 0.0001;


using namespace testing;

class FuncionalTest: public ::testing::Test{
protected:
    Model *m;
public:
    FuncionalTest();
    virtual ~FuncionalTest()=0;
};

#endif // FUNCTIONAL_TESTS_H
