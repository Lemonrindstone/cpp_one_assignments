#include <gtest/gtest.h>

#include "../include/algo.hpp"

// Demonstrate some basic assertions.
TEST(FIBBONACCI_TEST, BasicAssertions) {
    // Expect equality.
    const long result = fibonacci(6);

    EXPECT_EQ(result, 8);
}

TEST(LINEAR_SEARCH_TEST, BasicAssertions) {
    int input[5] = {1, 3, 5, 6, 5};
    Array* array = init(5, input);
    const int idx_result = linear_search(array, 3);

    EXPECT_EQ(idx_result, 1);
}

TEST(LINEAR_SEARCH_MISSING_TEST, BasicAssertions) {
    int input[3] = {1, 2, 3};
    Array* array = init(3, input);

    const int idx_result = linear_search(array, 6);
    EXPECT_EQ(idx_result, -1);
}

TEST(FACTORIAL_TEST, BasicAssertions) {
    long result = factorial(5);
    EXPECT_EQ(result, 120);
}

TEST(FIZZBUZZ_TEST, BasicAssertions) { 
    const int n = 3;
    std::string result = fizz_buzz_checker(n);
    EXPECT_EQ(result, "fizz");
}
