#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::swap, std::cout, std::exception;

static void bubbleSort(int*& array, const int& arrayLength)
{

    for (int i = 0; i < arrayLength; ++i)
    {
        bool isSorted = true;
        for (int j = i + 1; j < arrayLength; ++j)
            if (array[i] > array[j]) { swap( array[i], array[j]); isSorted = false; }
        if (isSorted) return;
    }
}


[[maybe_unused]] static void bubbleSort2(int*& array, const int& arrayLength)
{

    for (int i = 0; i < arrayLength; ++i)
    {
        bool isSorted = true;
        for (int j = 1; j < arrayLength - i; ++j)
            if (array[j] > array[j - 1]) { swap( array[j], array[j - 1]); isSorted = false; }
        if (isSorted) return;
    }
}
