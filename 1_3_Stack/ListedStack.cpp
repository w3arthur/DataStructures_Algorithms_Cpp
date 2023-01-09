#include "ListedStack.h"

bool LinkedStack::isEmpty() const { return items.empty(); }

void LinkedStack::push(int value) { items.push_back(value); }

int LinkedStack::peak() {
    if(isEmpty()) throw exception();
    return items.back();
}

int LinkedStack::pop() {
    int i  = items.back();
    items.pop_back();
    return  i;
}

string LinkedStack::print() const {
    string str{};
    for (auto it: items) str += to_string(it) + " ";
    return str;
}
