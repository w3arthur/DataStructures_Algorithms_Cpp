#include "QueueCircular.h"

bool QueueCircular::isEmpty() const { return count == 0; }

bool QueueCircular::isFull() const { return itemsLength == count; }

void QueueCircular::enqueue(int value) {
    if(isFull()) throw exception();
    items[last] = value;
    last = (last + 1) % itemsLength;
    count ++;
}

int QueueCircular::dequeue() {
    if(isEmpty()) throw exception();
    int value = items[first];
    first = (first +1) % itemsLength;
    count --;
    return value;   //return items[--count];
}

string QueueCircular::print() const {
    string str{};
    for(int i = first; i < count; ++i) str += to_string(items[i]) + " ";
    return str;
}

