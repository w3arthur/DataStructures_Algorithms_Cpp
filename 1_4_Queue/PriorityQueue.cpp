//use memcopy to allocate
// delete[](items);  issue
#pragma once
#include <string>
using std::string, std::to_string, std::exception;
class QueueArray
{
private:
    int* items;
    int itemsLength;
    int count;
    int first;
    bool isEmpty() const { return count == 0;}
    bool isFull() const { return count == itemsLength;}
/*    void allocate()
    {
        int* newQueue = new int[itemsLength * 2];
        for(int i = first ; i < count; ++i) newQueue[i - first] = items[i];
        count -= first;
        first = 0;
        itemsLength *= 2;
        //delete[](items);
        items = newQueue;
    }*/
public:
    explicit QueueArray() : itemsLength{10}, items{new int[itemsLength]}, count{}, first{} {  }
    ~QueueArray(){ delete[](items); }
    void enqueue(int value)
    {
        if(isFull()) throw exception(); // allocate(); // allocate
        for(int i = count - 1; i >= first; i--)
        {   //moving
            if (items[i] > value) { items[i + 1] = items[i]; }
            else { items[i + 1] = value; break; }
        }
        count ++;
    }
    int dequeue()
    {
        if(isEmpty()) throw exception();
        int value = items[first];
        first++;
        return value;   //return items[--count];
    }
    string print() const
    {
        string str{};
        for(int i = first; i < count; ++i) str += to_string(items[i]) + " ";
        return str;
    }
};