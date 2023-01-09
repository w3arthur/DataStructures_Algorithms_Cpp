//Improve print() method

#pragma once
#include <iostream>
#include <string>
#include <list>

using std::list, std::string, std::to_string, std::exception, std::cout;
class LinkedStack
{
    list<int> items;
    [[nodiscard]] bool isEmpty() const;
public:
    explicit LinkedStack() : items{} { }
    ~LinkedStack()= default;

    void push(int value);

    [[maybe_unused]] int peak();
    int pop();
    [[nodiscard]] string print() const;
};