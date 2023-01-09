#pragma once
#include "Pair.h"   //#include <iostream>
#include <list>
#include <utility>
using std::pair, std::list, std::to_string, std::begin, std::end, std::cout, std::endl ;
//std::move

class HashtableChaining
{
    static const int HASHTABLE_LENGTH = 10;
    //list<pair<int, string>>* hashtable;
    list<struct Pair>* hashtable;

    static int hashFunction(int key);

    [[maybe_unused]] list<Pair> getList(int key);

public:
    HashtableChaining() : hashtable{new list<struct Pair>[HASHTABLE_LENGTH]} { }

    ~HashtableChaining(){ delete[](hashtable); }

    [[nodiscard]] bool isEmpty() const;

    void insert (int key, const string& value);

    void remove(int key);

    [[nodiscard]] string print() const;
};