
#pragma once
#include <iostream>
#include <string>
#include <cmath>
using std::string, std::to_string, std::swap, std::cout, std::exception;

static int jumpSearch(int*& array, const int& arrayLength, const int& target)
{
    int blockSize = (int)std::sqrt(arrayLength);
    int left = 0;
    int right = blockSize;
    while (array[right - 1] < target )
    {
        if(left >= arrayLength) break;
        left = right;   //if (start >= array.length) break;	//edge case
        right += blockSize;
        if (right > arrayLength) right = arrayLength;
    }
    for (int i = left; i < right; i++) if (array[i] == target) return i;
    return -1;
}

