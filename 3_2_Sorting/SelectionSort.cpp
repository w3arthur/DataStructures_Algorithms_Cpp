#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::swap, std::cout, std::exception;

static void selectionSort(int*& array, const int& arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        auto selection = i;  //minValue
        for (auto j = i; j < arrayLength; ++j) if (array[selection] > array[j]) selection = j;
        swap(array[i], array[selection]);
    }
}



static int findMinIndex(int*& array, const int& arrayLength, int& i);
[[maybe_unused]]
static void selectionSort2(int*& array, const int& arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        int selection = findMinIndex(array, arrayLength, i);
        swap(array[i], array[selection]);
    }
}
static int findMinIndex(int*& array, const int& arrayLength, int& i) {
    auto selection = i;  //minValue
    for (auto j = i; j < arrayLength; ++j) if (array[selection] > array[j]) selection = j;
    return selection;
}