#pragma once
#include <iostream>
#include <string>
#include "heap.cpp"
//move to smart pointer
//move to string_view to print
//fix destructures!     List.root   List.last
//delete in the middle
using std::string, std::to_string, std::cout;
class PriorityQueue {   //for example only
private:
    Heap heap;
public:
    explicit PriorityQueue(): heap{} {}
    ~PriorityQueue() { }
    void Enqueue(int item) { heap.insert(item); }
    int Dequeue() { return heap.remove(); }
    bool IsEmpty() { return heap.isEmpty(); }
};