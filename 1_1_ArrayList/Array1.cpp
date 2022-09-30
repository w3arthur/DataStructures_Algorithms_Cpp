#pragma once
#include <iostream>
#include <string>
using std::string, std::to_string, std::cout,std::exception;
class Array1
{
private:
    int* itemArray{};
    int arrayLength{};
    int count{}; //count
    void resize() {
        int* newArray = new int[arrayLength * 2];
        for (int i = 0; i < arrayLength; ++i)
            newArray[i] = itemArray[i];
        //delete itemArray;
        itemArray = newArray;
        arrayLength *= 2;
    };
    [[nodiscard]] bool needToReSize() const { return arrayLength == count; };
    [[nodiscard]] bool needToReSize(int index) const { return index >= count; };
public:
    explicit Array1(int length) : count{}, arrayLength{length}, itemArray{new int[length]}  { }
    Array1() { Array1(5); }
    [[nodiscard]] bool contains(int item) const { return indexOf(item) != -1; };
    int indexOf(int& item) const {
        for (int i{}; i < count; ++i) if (itemArray[i] == item) return i;
        return -1;
    };
    ~Array1(){delete[](itemArray);}
    [[maybe_unused]] int lastIndexOf(int item) { return itemArray[indexOf(item)]; };
    [[maybe_unused]] int get(int index) { return itemArray[index]; };
    [[nodiscard]] int size() const { return count; };
    int add(int item) {
        if (needToReSize()) resize();
        itemArray[count] = item;
        count++;
        return item;
    }
    [[maybe_unused]] int set(const int index, const int item) {
        if (needToReSize(index)) throw exception();
        itemArray[index] = item;
        return item;
    };
    int remove(const int index) {
        int item = itemArray[index];
        if (needToReSize(index)) throw exception();
        for (int i = index; i < count; i++) itemArray[i] = itemArray[i + 1];
        count--;
        return item;
    };
    [[maybe_unused]] int removeItem(int& item) { return remove(indexOf(item)); };
    void print() const {
        for (int i = 0; i < count; ++i) cout << itemArray[i] << ", ";
        cout << "\n";
    }
};
