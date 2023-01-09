#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::cout, std::exception;
class Stack
{
    int itemsLength;
    int* items;
    int count;
    [[nodiscard]] bool isEmpty() const;
    void allocate();
public:
    explicit Stack() : itemsLength{10}, items{new int[itemsLength]}, count{} { }
    ~Stack(){ delete[](items); }
    void push(int value);

    [[maybe_unused]] int peak();
    int pop();
    [[nodiscard]] string print() const;
};