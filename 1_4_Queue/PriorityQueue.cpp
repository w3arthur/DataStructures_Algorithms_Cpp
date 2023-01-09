#include "PriorityQueue.h"

bool QueueArrayPriority::isEmpty() const { return count == 0; }

bool QueueArrayPriority::isFull() const { return count == itemsLength; }

/*void QueueArrayPriority::allocate() {
    int* newQueue = new int[itemsLength * 2];
    for(int i = first ; i < count; ++i) newQueue[i - first] = items[i];
    count -= first;
    first = 0;
    itemsLength *= 2;
    //delete[](items);
    items = newQueue;
}*/


void QueueArrayPriority::enqueue(int value) {
    if(isFull()) throw exception(); // allocate(); // allocate
    for(int i = count - 1; i >= first; i--)
    {   //moving
        if (items[i] > value) { items[i + 1] = items[i]; }
        else { items[i + 1] = value; break; }
    }
    count ++;
}

int QueueArrayPriority::dequeue() {
    if(isEmpty()) throw exception();
    int value = items[first];
    first++;
    return value;   //return items[--count];
}

string QueueArrayPriority::print() const {
    string str{};
    for(int i = first; i < count; ++i) str += to_string(items[i]) + " ";
    return str;
}

