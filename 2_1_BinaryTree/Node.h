#pragma once
#include <iostream>

using std::string, std::cout, std::endl;


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    explicit Node(int data) : data{data}, left{nullptr}, right{nullptr} {}
    ~Node() { delete left; delete right; cout << "del:" << data << endl; }
};