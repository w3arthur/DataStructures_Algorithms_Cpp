#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using std::string, std::to_string, std::swap, std::cout, std::exception;
static void countingSort(int*& array, const int& arrayLength)
{
    auto maxValue =  *std::max_element(array, array+arrayLength - 1 );
    int countsLength = maxValue + 1;
    int* counts = new int[countsLength];
    for(int c{}; c< countsLength; ++c) counts[c] = 0;
    for(int item{}; item< arrayLength; ++item) counts[array[item]] ++ ; //increment
    int index{};
    for (int i{}; i < countsLength; ++i) //coping x times TO OUTPUT array
        for (int j{}; j < counts[i]; j++) array[index++] = i;
    delete[](counts);
}
