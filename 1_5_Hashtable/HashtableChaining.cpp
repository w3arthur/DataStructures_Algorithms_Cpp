#pragma once
#include <iostream>
#include <string>
#include <list>
#include <utility>
using std::pair, std::list, std::string, std::to_string, std::begin, std::end, std::cout, std::endl ;
//std::move
class HashtableChaining
{
private:
    struct Pair
    {
        int key;
        string value;
        explicit Pair(int key, string value) : key{key}, value{std::move(value)} { }
        ~Pair()= default;
    };
    static const int HASHTABLE_LENGTH = 10;
    //list<pair<int, string>>* hashtable;
    list<struct Pair>* hashtable;
    static int hashFunction(int key) { return key % HASHTABLE_LENGTH; };
    [[maybe_unused]] list<Pair> getList(int key) { return hashtable[key]; };
public:
    HashtableChaining() : hashtable{new list<struct Pair>[HASHTABLE_LENGTH]} { }
    ~HashtableChaining(){ delete[](hashtable); }
    [[nodiscard]] bool isEmpty() const
    {
        for (int i{}; i < HASHTABLE_LENGTH; ++i) if(!hashtable[i].empty()) return false;
        return true;
    };
    void insert (int key, const string& value)
    {
        auto& cell = hashtable[hashFunction(key)];
        bool keyExists = false;
        //for(auto it = begin(cell);it != end(cell); it++){
        for(auto& it : cell)
            if(it.key == key) /*first in pair*/
            {
                keyExists = true;
                it.value = value; //new value
                break;
            }
        if(!keyExists) cell.emplace_back(Pair(key, value)); //?
    }
    void remove(int key)
    {
        auto& cell = hashtable[hashFunction(key)];
        bool keyExists = false;

        for(auto it = begin(cell);it != end(cell); it++)
            if(it->key == key)   /*first in pair*/
            {
                keyExists = true;
                cell.erase(it); //new iterator
                break;
            }
        if(!keyExists) {cout << "item not found to delete " << to_string(key) << endl; } //?
    }
    [[nodiscard]] string print() const
    {
        string str{};
        for(int i{}; i < HASHTABLE_LENGTH; ++i){
            if(hashtable[i].empty()) continue;
            for(auto& it :hashtable[i]) str += "the key:" + to_string(it.key) + " value: " + it.value +"\n";
        }
        return str;
    }
};