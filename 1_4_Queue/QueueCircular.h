//use memcopy to allocate
// delete[](items);  issue
#pragma once
#include <string>
#include "QueueCircular.h"

using std::string, std::to_string, std::exception;
class QueueCircular
{
    int* items;
    int itemsLength;
    int count;
    int first;
    int last;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
public:
    explicit QueueCircular() : itemsLength{10}, items{new int[itemsLength]}, count{}, first{}, last{} {  }
    ~QueueCircular(){ delete[](items); }
    void enqueue(int value);
    int dequeue();
    [[nodiscard]] string print() const;
};
