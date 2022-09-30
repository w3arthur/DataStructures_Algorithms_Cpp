#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::swap, std::cout, std::exception;

static void quickSort(int*& array, int start, int end);
static void quickSort(int*& array, const int& arrayLength)
{
    quickSort(array, 0, arrayLength - 1);
}

static int pivotSort(int*& array, int start, int end);
static void quickSort(int*& array, int start, int end)
{
    if (start >= end) return;   //base condition (single element / no elements)
    auto pivot = pivotSort(array, start, end);
    quickSort(array, start, pivot - 1); //Sort left
    quickSort(array, pivot + 1, end); //Sort right
}

static int pivotSort(int*& array, int start, int end)
{
    auto pivotSet = array[end];    //! //(start+end)/2 + 1
    auto pivot = start - 1; // will be the new partition // right partition starts from index 0
    for (auto i = start; i <= end; i++)
        if (array[i] <= pivotSet) swap(array[i], array[++pivot]);
    return pivot;    //index of the pivot after its move
}