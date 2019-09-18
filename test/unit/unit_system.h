#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/system.h"

class UnitTestSystem: public ::testing::Test{
protected:
    System *s;
public:
    UnitTestSystem();
    virtual ~UnitTestSystem()=0;
};


#endif // UNIT_SYSTEM_H
