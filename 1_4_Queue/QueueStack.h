//use memcopy to allocate
// delete[](items);  issue
#pragma once
#include <iostream>
#include <stack>
#include <string>
using std::stack, std::string, std::to_string, std::exception;
class QueueStack
{
    stack<int> queueStack; //stackA
    stack<int> enqueueStack; //stackB
    [[maybe_unused]] [[nodiscard]] bool isEmpty() const;
public:
    explicit QueueStack() : queueStack{}, enqueueStack{} {  }
    ~QueueStack()= default;
    void enqueue(int value);
    int dequeue();
    string print();
};