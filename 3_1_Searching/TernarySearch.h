#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::swap, std::cout, std::exception;
static int ternarySearch(const int*& array, const int& target, int left, int right);
static int ternarySearch(const int* array, const int& arrayLength, const int target)
{
    return ternarySearch(array, target, 0, arrayLength -1);
}

static int ternarySearch(const int*& array, const int& target, int left, int right)
{
    if (right < left) return -1;
    int partitionSize = (right -left)/3;
    int mid1 = left + partitionSize;
    int mid2 = right - partitionSize;
    if (array[mid1] == target) return mid1;
    else if (array[mid2] == target) return mid2;
    else if (target < array[mid1]) return ternarySearch(array, target, left, mid1 - 1);
    else if (target < array[mid2]) return ternarySearch(array, target, mid1 + 1, mid2 - 1);
    else return ternarySearch(array, target, mid2 + 1, right);
}

