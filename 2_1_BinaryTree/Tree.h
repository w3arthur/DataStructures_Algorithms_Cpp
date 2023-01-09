#pragma once
#include "Node.h"   // #include <iostream>
#include <list>

using std::to_string, std::list, std::exception;
//std::min, std::max;

class TreeAvl {

    struct Node *root;
    static bool isNull(const Node *node);
    static bool isLeaf(const Node *node);
    int height(const Node *node) const;
    int min(const Node *node) const;
    bool equals(Node *a, Node *b) const;
    bool isBinarySearchTree(Node *node, int min, int max) const;
    void getNodesAtDistance(Node *node, int distance, list<int> *list) const;
    /*1*/
    int size(Node* node) const;
    /*2*/
    int countLevels(Node* node, int level) const;
    /*3*/
    int max(Node *node) const;

    bool contains(Node* node, int &data) const;

    void traversePreOrder(Node *node) const;

    void traverseInOrder(Node *node) const;

    void traversePostOrder(Node *node) const;

    void TraverseInOrder2(Node* node, list<int>* list) const;    //the recursion

    /*AVL*/
    /*1*/
    bool isBalanced(Node* node) const;

    /*2*/
    bool isPerfect(Node* node) const;

public:
    explicit TreeAvl() : root(nullptr) { }
    ~TreeAvl(){ delete root; }
    void insert(int data);

    bool find(int data);

    int height();

    int min();

    int min_binarySearchTree();

    bool equals(const TreeAvl *other);

    [[maybe_unused]] bool isBinarySearchTree();

    [[maybe_unused]] void swapRoot();

    list<int> getNodesAtDistance(int distance);

    void traverseLevelOrder();

    /*1*/
    int size();
    /*2*/
    int countLevels();    //height with recursion
    /*3*/
    int max();

    bool contains(int data);

    void traversePreOrder();      // Root, Left, Right

    void traverseInOrder();       // Left, Root, Right

    void traversePostOrder();     // Left, Right, Root

    int Size2();  //with recursion

    string print();

    /*AVL*/
    /*1*/
    [[maybe_unused]] bool isBalanced();

    /*2*/
    [[maybe_unused]] bool isPerfect();

};