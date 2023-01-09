#pragma once
#include <iostream>

using std::string;


struct Pair
{
    int key;
    string value;
    explicit Pair(int key, string value) : key{key}, value{std::move(value)} { }
    ~Pair()= default;
};