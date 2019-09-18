#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/model.h"
#include "../myflow.h"


class UnitTestModel: public ::testing::Test{
protected:
    Model *m;
public:
    UnitTestModel();
    virtual ~UnitTestModel()=0;
};


#endif // UNIT_MODEL_H
