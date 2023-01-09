#pragma once

#include <iostream>
#include <string>
using std::string, std::to_string, std::cout,std::exception;
class Array1
{
    int* itemArray{};
    int arrayLength{};
    int count{}; //count
    void resize();
    [[nodiscard]] bool needToReSize() const;
    [[nodiscard]] bool needToReSize(int index) const;
public:
    explicit Array1(int length) : count{}, arrayLength{length}, itemArray{new int[length]}  { }
    explicit Array1() { Array1(5); }
    [[nodiscard]] bool contains(int item) const ;
    int indexOf(int& item) const ;
    ~Array1(){ delete[](itemArray); }
    [[maybe_unused]] int lastIndexOf(int item);
    [[maybe_unused]] int get(int index);
    [[nodiscard]] int size() const { return count; };
    int add(int item);
    [[maybe_unused]] int set(int index, int item);
    int remove(int index);
    [[maybe_unused]] int removeItem(int item);
    void print() const;
};
