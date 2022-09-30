#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::cout, std::exception;
class Stack
{
private:
    int itemsLength;
    int* items;
    int count;
    [[nodiscard]] bool isEmpty() const { return count == 0;}
    void allocate()
    {
        int* newStack = new int[itemsLength * 2];
        for(int i = 0; i < count; ++i )  newStack[i] = items[i];
        delete[](items);
        itemsLength *= 2;
        items = newStack;
    }
public:
    explicit Stack() : itemsLength{10}, items{new int[itemsLength]}, count{} { }
    ~Stack(){ delete[](items); }
    void push(int value){
        if(itemsLength == count) allocate();//throw 0; //or allocate
        items[count] = value;
        count ++;
    }

    [[maybe_unused]] int peak(){
        if(isEmpty()) throw exception();
        return items[count - 1];
    }
    int pop(){
        if(isEmpty()) throw exception();
        int value = items[count - 1];
        count --;
        return value;
    }
    [[nodiscard]] string print() const
    {
        string str{};
        for (int i{}; i < count; ++i){
            str += to_string(items[i]) + " ";
        }
        return str;
    }
};