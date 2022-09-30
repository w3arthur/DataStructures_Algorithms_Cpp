#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "BinarySearch.cpp"

using std::string, std::to_string, std::swap, std::cout, std::exception;
static int exponentialSearch(int*& array, const int& arrayLength, const int& target)
{
    int right = 1;
    while(array[right] < target) {
        right *= 2;
        if (right >= arrayLength) { right = arrayLength - 1; break; }
    }
    const int newArrayLength = right+1-(right/2) ;
    int* newArray = new int[newArrayLength];
    memcpy(newArray, &array[right/2], newArrayLength* sizeof(int));
    int search = binarySearch(newArray, newArrayLength, target);
    delete[](newArray);
    return search >= 0 ?  right/2 + search : -1 ;
}
