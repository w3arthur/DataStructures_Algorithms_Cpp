#pragma once
#include <iostream>

using std::cout, std::endl;

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
    explicit Node(int data) : data{data}, left{nullptr}, right{nullptr}, height{} {}
    ~Node() { delete left; delete right; cout << "del:" << data << endl; }
};