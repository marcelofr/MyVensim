#include "unit_tests.h"

int UnitTestFlow(){
    ::testing::InitGoogleTest();
    ::testing::GTEST_FLAG(filter) = "UnitTestFlow*";
    return RUN_ALL_TESTS();
}

int UnitTestModel(){
    ::testing::InitGoogleTest();
    ::testing::GTEST_FLAG(filter) = "UnitTestModel*";
    return RUN_ALL_TESTS();
}

int UnitTestSystem(){
    ::testing::InitGoogleTest();
    ::testing::GTEST_FLAG(filter) = "UnitTestSystem*";
    return RUN_ALL_TESTS();
}
