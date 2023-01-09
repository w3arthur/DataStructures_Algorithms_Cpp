#pragma once
#include "Node.h"   //#include <iostream>

#include <string>
#include <list>
#include <cmath>

using std::string, std::to_string, std::list, std::exception;
//std::max

class TreeAvl {

    Node *root;
    static bool isNull(const Node *node);
    static bool isLeaf(const Node *node);
    static int getHeight(Node *node);
    static int getMaxHeight(Node *node);
    static int balanceFactor(Node *node);

    Node* insert(int value, Node* node, Node* newNode) const;

    static Node* balance(Node *node);

    static Node* rotateLeft(Node* node);

    static Node* rotateRight(Node* node);

    int height(Node *node) const;

    void getNodesAtDistance(Node* node, int distance, list<int>* list) const;

    bool isPerfect(Node* node) const;

public:
    explicit TreeAvl() : root{nullptr} { }
    ~TreeAvl(){ delete root; }

    void insert(int data);

    int height();

    list<int> getNodesAtDistance(int distance);

    string traverseLevelOrder();

    string print();

    /*1*/
    [[maybe_unused]] bool isBalanced();
    /*2*/
    [[maybe_unused]] bool isPerfect();
};

