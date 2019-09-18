#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../myflow.h"

class UnitTestFlow: public ::testing::Test{
protected:
    ExpFlow *ef;
public:
    UnitTestFlow();
    virtual ~UnitTestFlow()=0;
};

#endif // UNIT_FLOW_H
