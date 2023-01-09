#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using std::string, std::to_string, std::list, std::swap, std::cout, std::exception;

static list<int>* creatBuckets(int*& array, const int& arrayLength , int numberOfBuckets);
static void bucketSort(int*& array, const int& arrayLength, int numberOfBuckets)
{

    auto buckets = creatBuckets(array, arrayLength, numberOfBuckets);
    auto index = 0;
    for(int i{};  i < numberOfBuckets;  ++i)
    {
        buckets[i].sort();
        for (auto item : buckets[i]) array[index++] = item;
    }
    delete[](buckets);
}

static list<int>* creatBuckets(int*& array, const int& arrayLength , const int numberOfBuckets)
{
    auto* buckets = new list<int>[numberOfBuckets];    //not initialized
    for (int i{}; i < numberOfBuckets; ++i) buckets[i] = list<int>{}; //initialize each element as list
    for(int item{}; item < arrayLength; ++item)
        buckets[ array[item]  / numberOfBuckets ].push_back(array[item]);
    return buckets;
}