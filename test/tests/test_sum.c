#include "sum.h"
#include "unity.h"

#include <stdlib.h>
#include <string.h>

void setUp(void)
{
    /* Set stuff up here */
}

void tearDown(void)
{
    /* Clean stuff up here */
}

void test_sum_function(void)
{
    /* Check result */
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, integer_sum(0, 0), "Error in integer_sum");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, integer_sum(0, 1), "Error in integer_sum");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, integer_sum(1, 0), "Error in integer_sum");
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, integer_sum(-1, 1), "Error in integer_sum");
    TEST_ASSERT_EQUAL_INT_MESSAGE(-1, integer_sum(-1, 0), "Error in integer_sum");
    TEST_ASSERT_EQUAL_INT_MESSAGE(-2, integer_sum(-1, -1), "Error in integer_sum");
    TEST_ASSERT_EQUAL_INT_MESSAGE(25, integer_sum(10, 15), "Error in integer_sum");
    TEST_ASSERT_EQUAL_INT_MESSAGE(-50, integer_sum(100, -150), "Error in integer_sum");
}

