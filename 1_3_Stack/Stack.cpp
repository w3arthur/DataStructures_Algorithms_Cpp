#include "Stack.h"

bool Stack::isEmpty() const { return count == 0; }

void Stack::allocate() {
    int* newStack = new int[itemsLength * 2];
    for(int i = 0; i < count; ++i )  newStack[i] = items[i];
    delete[](items);
    itemsLength *= 2;
    items = newStack;
}

void Stack::push(int value) {
    if(itemsLength == count) allocate();//throw 0; //or allocate
    items[count] = value;
    count ++;
}

int Stack::peak() {
    if(isEmpty()) throw exception();
    return items[count - 1];
}

int Stack::pop() {
    if(isEmpty()) throw exception();
    int value = items[count - 1];
    count --;
    return value;
}

string Stack::print() const {
    string str{};
    for (int i{}; i < count; ++i){
        str += to_string(items[i]) + " ";
    }
    return str;
}

