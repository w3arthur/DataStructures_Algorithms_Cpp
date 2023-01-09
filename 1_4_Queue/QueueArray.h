//use memcopy to allocate
// delete[](items);  issue
#pragma once
#include <string>
using std::string, std::to_string, std::exception;
class QueueArray
{
    int itemsLength;
    int* items;
    int count;
    int first;
    [[nodiscard]] bool isEmpty() const;
    void allocate();
public:
    explicit QueueArray() : itemsLength{10}, items{new int[itemsLength]}, count{}, first{} {  }
    ~QueueArray(){ delete[](items); }
    void enqueue(int value);
    int dequeue();
    [[nodiscard]] string print() const;
};