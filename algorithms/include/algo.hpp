#ifndef ALGO_H_
#define ALGO_H_

#include "types.hpp"
#include <iostream>
#include <string>

long fibonacci(const int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int linear_search(Array * a, const int target)
{ 
    std::cout << a->data[0] << std::endl;
    return target;
}

long factorial(const int n)
{
    return n;
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
