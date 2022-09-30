//Improve print() method

#pragma once
#include <iostream>
#include <string>
#include <list>

using std::list, std::string, std::to_string, std::exception, std::cout;
class LinkedStack
{
private:
    list<int> items;
    [[nodiscard]] bool isEmpty() const { return items.empty(); };
public:
    explicit LinkedStack() : items{} { }
    ~LinkedStack()= default;

    void push(int value){ items.push_back(value); }

    [[maybe_unused]] int peak(){
        if(isEmpty()) throw exception();
        return items.back();
    }
    int pop(){
        int i  = items.back();
       items.pop_back();
       return  i;
    }
    [[nodiscard]] string print() const
    {
        string str{};
        for (auto it: items) str += to_string(it) + " ";
        return str;
    }
};