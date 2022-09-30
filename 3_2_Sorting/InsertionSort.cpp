#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::swap, std::cout, std::exception;

static void insertionSort(int*& array, const int& arrayLength)
{
    for (int i = 1; i < arrayLength; ++i)
    {
        auto current = array[i];
        int j = i;
        for(; j > 0; --j)
        {
            if(array[j - 1] <= current) break;
            array[j] = array[j - 1];    //shiftRight
        }
        array[j] = current;
    }
}


[[maybe_unused]] static void insertionSort2(int*& array, const int& arrayLength)
{
    for (int i = 1; i < arrayLength; ++i)
    {
        auto current = array[i];
        int j = i - 1;
        for(; j >= 0; --j)
        {
            if(array[j] > current) break;
            array[j + 1] = array[j];
        }

        array[j + 1] = current;
    }
}

