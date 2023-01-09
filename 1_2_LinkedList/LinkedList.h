#pragma once
#include "Node.h"   //#include <iostream>

//move to smart pointer
//move to string_view to print
//fix destructures!     List.root   List.last
//delete in the middle
using std::string, std::to_string, std::cout, std::exception;
class List
{
    struct Node* root;
    struct Node* last;
    int count;
    bool isReversed;
    [[nodiscard]] bool isEmpty() const;
    void resetList(){ delete root; root=nullptr; last=nullptr; }
public:
    explicit List() : root{nullptr}, last{nullptr}, count{}, isReversed{false} { }
    ~List(){ while(root != nullptr && !isReversed) { removeLast(); } }
    void insertLast(int data);
    void insertFirst(int data);
    [[maybe_unused]] int removeFirst();
    int removeLast();

    int kth(int subPlace);

    void reverse();

    [[nodiscard]] string print() const;
};