//use memcopy to allocate
// delete[](items);  issue
#pragma once
#include <string>
using std::string, std::to_string, std::exception;
class QueueArray
{
private:
    int itemsLength;
    int* items;
    int count;
    int first;
    [[nodiscard]] bool isEmpty() const { return count == 0;}
    void allocate()
    {
        int* newQueue = new int[itemsLength * 2];
        for(int i = first ; i < count; ++i) newQueue[i - first] = items[i];
        count -= first;
        first = 0;
        delete[](items);
        itemsLength *= 2;
        items = newQueue;
    }
public:
    explicit QueueArray() : itemsLength{10}, items{new int[itemsLength]}, count{}, first{} {  }
    ~QueueArray(){ delete[](items); }
    void enqueue(int value)
    {
        if(count == itemsLength) allocate();//throw exception();
        items[count] = value;
        count ++;
    }
    int dequeue()
    {
        if(isEmpty()) throw exception();
        int value = items[first];
        first++;
        return value;   //return items[--count];
    }
    [[nodiscard]] string print() const
    {
        string str{};
        for(int i = first; i < count; ++i) str += to_string(items[i]) + " ";
        return str;
    }
};