#ifndef ALGO_H_
#define ALGO_H_

#include "types.hpp"
#include <iostream>
#include <string>

long fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int linear_search(Array* a, const int target) {
    for (int i = 0; i < a->len; i++) {
        if (a->data[i] == target) {
            return i;
        }
    }
    return -1;
}

long factorial(const int n) {
    if (n == 0)
        return 1;
    else {
        return n * factorial(n - 1);
    }
}

std::string fizz_buzz_checker(const int n) {
    if (n % 15 == 0) {
        return "fizzbuzz";
    }
    else if (n % 5 == 0)
    {
        return "buzz";
    }
    else if (n % 3 == 0)
    {
        return "fizz";
    }
    return "";
}

#endif // ALGO_H_
