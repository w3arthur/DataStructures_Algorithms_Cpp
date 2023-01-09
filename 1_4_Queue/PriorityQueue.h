//use memcopy to allocate
// delete[](items);  issue
#pragma once
#include <string>
using std::string, std::to_string, std::exception;
class QueueArrayPriority
{
    int* items;
    int itemsLength;
    int count;
    int first;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
    //void allocate();
public:
    explicit QueueArrayPriority() : itemsLength{10}, items{new int[itemsLength]}, count{}, first{} {  }
    ~QueueArrayPriority(){ delete[](items); }
    void enqueue(int value);
    int dequeue();
    [[nodiscard]] string print() const;
};