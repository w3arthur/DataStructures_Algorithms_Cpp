#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::swap, std::cout, std::exception;
static int binarySearch(int*& array, const int& arrayLength, const int& target)
{
    int left{};
    int right = arrayLength - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if(array[middle] == target) return middle;
        else if(array[middle] > target) right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}


static int binarySearch_Recursion(int*& array, const int& target, int left, int right);
static int binarySearch_Recursion(int*& array, const int& arrayLength, const int& target)
{
    return binarySearch_Recursion(array, target, 0, arrayLength-1);
}
static int binarySearch_Recursion(int*& array, const int& target, int left, int right)
{
    if (right < left) return -1; //edge race condition
    int middle = (left + right) / 2;
    if (array[middle] == target) return middle;
    else if (target < array[middle]) return binarySearch_Recursion(array, target, left, middle - 1);
    else return binarySearch_Recursion(array, target, middle + 1, right);
}
