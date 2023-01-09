#include "QueueStack.h"

bool QueueStack::isEmpty() const { return queueStack.empty(); }

void QueueStack::enqueue(int value) { queueStack.push(value); }

int QueueStack::dequeue() {
    if(queueStack.empty()) throw exception();
    while(!queueStack.empty()) {enqueueStack.push(queueStack.top()); queueStack.pop();}
    int value = enqueueStack.top();
    enqueueStack.pop();
    while(!enqueueStack.empty()) {queueStack.push(enqueueStack.top()); enqueueStack.pop();}
    return value;
}

string QueueStack::print() {
    string str{};
    while(!queueStack.empty()) {enqueueStack.push(queueStack.top()); queueStack.pop();}
    while(!enqueueStack.empty()) {
        str += to_string(enqueueStack.top()) + " ";
        queueStack.push(enqueueStack.top());
        enqueueStack.pop();
    }
    return str;
}
