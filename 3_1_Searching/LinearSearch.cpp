
#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::swap, std::cout, std::exception;
static int linearSearch(int*& array, const int& arrayLength, const int& target)
{
    for (int i{}; i < arrayLength; ++i) if(array[i] == target) return i;
    return -1;
}

