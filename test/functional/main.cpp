#include <gtest/gtest.h>

#include "functional_tests.h"


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    //::testing::GTEST_FLAG(filter) = "Exponential*";
    //::testing::GTEST_FLAG(filter) = "Logistic*";
    //::testing::GTEST_FLAG(filter) = "Complex*";
    return RUN_ALL_TESTS();
}
