#include "QueueArray.h"

bool QueueArray::isEmpty() const { return count == 0; }

void QueueArray::allocate() {
    int* newQueue = new int[itemsLength * 2];
    for(int i = first ; i < count; ++i) newQueue[i - first] = items[i];
    count -= first;
    first = 0;
    delete[](items);
    itemsLength *= 2;
    items = newQueue;
}

void QueueArray::enqueue(int value) {
    if(count == itemsLength) allocate();//throw exception();
    items[count] = value;
    count ++;
}

int QueueArray::dequeue() {
    if(isEmpty()) throw exception();
    int value = items[first];
    first++;
    return value;   //return items[--count];
}

string QueueArray::print() const {
    string str{};
    for(int i = first; i < count; ++i) str += to_string(items[i]) + " ";
    return str;
}


