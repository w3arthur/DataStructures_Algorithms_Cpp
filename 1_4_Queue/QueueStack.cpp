//use memcopy to allocate
// delete[](items);  issue
#pragma once
#include <iostream>
#include <stack>
#include <string>
using std::stack, std::string, std::to_string, std::exception;
class QueueStack
{
private:
    stack<int> queueStack; //stackA
    stack<int> enqueueStack; //stackB
    [[maybe_unused]] [[nodiscard]] bool isEmpty() const { return queueStack.empty();}
public:
    explicit QueueStack() : queueStack{}, enqueueStack{} {  }
    ~QueueStack()= default;
    void enqueue(int value) { queueStack.push(value);  }
    int dequeue()
    {
        if(queueStack.empty()) throw exception();
        while(!queueStack.empty()) {enqueueStack.push(queueStack.top()); queueStack.pop();}
        int value = enqueueStack.top();
        enqueueStack.pop();
        while(!enqueueStack.empty()) {queueStack.push(enqueueStack.top()); enqueueStack.pop();}
        return value;
    }
    string print()
    {
        string str{};
        while(!queueStack.empty()) {enqueueStack.push(queueStack.top()); queueStack.pop();}
        while(!enqueueStack.empty()) {
            str += to_string(enqueueStack.top()) + " ";
            queueStack.push(enqueueStack.top());
            enqueueStack.pop();
        }
        return str;
    }
};