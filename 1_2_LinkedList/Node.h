//
// Created by pc1 on 09/01/2023.
//
#pragma once
#include <iostream>
using std::string, std::to_string, std::cout, std::exception;
struct Node
{
    int data;
    struct Node* next;
    explicit Node(int data) : data{data}, next{nullptr} { }
    ~Node(){ cout << "del:" << data << "; "; }
};
