#pragma once
#include <iostream>
#include <string>
#include <list>
using std::string, std::to_string, std::cout, std::endl, std::list, std::exception;
//std::min, std::max;

class Tree {
private:
    struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
        explicit Node(int data) : data{data}, left{nullptr}, right{nullptr} {}
        ~Node() { delete left; delete right; cout << "del:" << data << endl; }
    };
    struct Node *root;
    static bool isNull(const Node *node){  return node == nullptr; }
    static bool isLeaf(const Node *node) { return isNull(node->left) && isNull(node->right) ; }
    int height(const Node *node) const
    {
        if(isNull(node)) return -1; //INT_MIN
        if(isLeaf(node)) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }
    int min(const Node *node) const
    {
        if(isNull(node)) return INT_MAX;
        if(isLeaf(node)) return node->data;
        auto left = min(node->left);
        auto right = min(node->right);
        return std::min(std::min(left, right), node->data);
    }
    bool equals(Node *a, Node *b) const
    {
        if(isNull(a) && isNull(b)) return true;
        if(!isNull(a) && !isNull(b))
            return
                a->data == b->data
                && equals(a->left, b->left)
                && equals(a->right, b->right);
        return false;
    }
    bool isBinarySearchTree(Node *node, int min, int max) const
    {
        if (isNull(node)) return true;
        if ( !(node->data >= min && node->data <= max) ) return false;
        return
            isBinarySearchTree(node->left, min, node->data)
            && isBinarySearchTree(node->right, node->data, max);
    }
    void getNodesAtDistance(Node *node, int distance, list<int> *list) const
    {
        if (isNull(node)) return;
        if (distance == 0) { list->push_back(node->data); /*System.out.print( node.value + " " );*/ return; }
        getNodesAtDistance(node->left, distance - 1, list);
        getNodesAtDistance(node->right, distance - 1, list);
    }
    /*1*/
    int size(Node* node) const
    {
        if (isNull(node)) return 0;
        return
                1
                + (!isNull(node->left) ? size(node->left) : 0)
                + (!isNull(node->right) ? size(node->right) : 0);
    }
    /*2*/
    int countLevels(Node* node, int level) const
    {
        if (isNull(node)) return level;
        return
                1
                + std::max(
                        countLevels(node->left, level)
                        , countLevels(node->right, level)
                );
    }
    /*3*/
    int max(Node *node) const
    {
        if (isNull(node)) return INT_MIN;
        return std::max(
                isNull(node->left) ? node->data : max(node->left)
                , isNull(node->right) ? node->data : max(node->right)
        );
    }
    bool contains(Node* node, int &data) const
    {
        if (isNull(node)) return false;
        if (data == node->data) return true;
        return contains(node->left, data) || contains(node->right, data); //O(n)
    }
    void traversePreOrder(Node *node) const
    {
        if (isNull(node)) return;   //base condition
        cout << node->data << " ";
        traversePreOrder(node->left);
        traversePreOrder(node->right);
    }
    void traverseInOrder(Node *node) const
    {
        if (isNull(node)) return;   //base condition
        traverseInOrder(node->left);
        cout << node->data << " ";
        traverseInOrder(node->right);
    }
    void traversePostOrder(Node *node) const
    {
        if (isNull(node)) return;   //base condition
        traversePostOrder(node->left);
        traversePostOrder(node->right);
        cout << node->data << " "; //Root
    }
    void TraverseInOrder2(Node* node, list<int>* list) const    //the recursion
    {   // from low to high  1 2 3 4 ...
        if (isNull(node)) return;   //base condition
        TraverseInOrder2(node->left, list);
        list->push_back(node->data);
        TraverseInOrder2(node->right, list);
    }
    /*AVL*/
    /*1*/
    bool isBalanced(Node* node) const
    {
        if (isNull(node)) return true;
        return abs(height(node->left) - height(node->right))  <= 1
               && isBalanced(node->left)
               && isBalanced(node->right);
    }
    /*2*/
    bool isPerfect(Node* node) const
    {
        if (isNull(node)) return true;
        return height(node->left) - height(node->right) == 0
               && isPerfect(node->left)
               && isPerfect(node->right);
    }
public:
    explicit Tree() : root(nullptr) { }
    ~Tree(){ delete root; }
    void insert(int data)
    {
        Node* node = new Node( data );
        if(isNull(root)) root = node;
        auto* current = root;
        while(true)
        {
            if(data < current->data)
            {
                if(isNull(current->left)){ current->left = node; break; }
                current = current->left;
            }
            else if (data > current->data)
            {
                if(isNull(current->right)){ current->right = node; break; }
                current = current->right;
            }
            else /*==*/ break;
        }
    }
    bool find(int data)
    {
        auto* current = root;
        while(!isNull(current))
        {
            if(data == current->data) return true;
            current = data < current->data ? current->left : current->right;
        }
        return false;
    }
    int height(){ return height(root); }
    int min(){ return min(root); }
    int min_binarySearchTree()
    {
        if(isNull(root)) throw exception();
        auto* current = root;
        while(!isNull(current->left)) current = current->left;
        int data = current->data;
        return data;
    }

    bool equals(const Tree *other)
    {
        if(other == nullptr) return false;
        return equals(root, other->root);
    }

    [[maybe_unused]] bool isBinarySearchTree() { return isBinarySearchTree(root, INT_MIN, INT_MAX); }
    [[maybe_unused]] void swapRoot(){ auto* temp = root->left; root->left= root->right; root->right = temp; }
    list<int> getNodesAtDistance(int distance)
    {
        list<int> list{};
        getNodesAtDistance(root, distance, &list); /*Console.WriteLine("");*/
        return list;
    }
    void traverseLevelOrder()
    {
        for (int i{}; i <= height(); ++i)
        {
            auto list = getNodesAtDistance(i);
            cout << i << "| ";
            for(auto data: list) cout << data << ", ";
            cout << "\n";
        }
    };

    /*1*/
    int size() { return size(root); }
    /*2*/
    int countLevels() { return countLevels(root, 0); }    //height with recursion
    /*3*/
    int max()
    {
        if (isNull(root)) throw exception();
        return std::max(max(root), root->data);
    }
    bool contains(int data) { return contains(root, data); }
    void traversePreOrder()      // Root, Left, Right
    {
        traversePreOrder(root);
        cout <<"\n";
    }
    void traverseInOrder()       // Left, Root, Right
    {
        traverseInOrder(root);
        cout <<"\n";
    }
    void traversePostOrder()     // Left, Right, Root
    {
        traversePostOrder(root);
        cout <<"\n";
    }
    int Size2()  //with recursion
    {
        list<int> list{};
        TraverseInOrder2(root, &list);
        int size = list.size();
        return size;
    }
    string print()
    {
        list<int> list{};
        TraverseInOrder2(root, &list);
        string str{};
        for(auto data: list){
            str += to_string(data) + ", ";
        }
        return str;
    }

    /*AVL*/
    /*1*/
    [[maybe_unused]] bool isBalanced()
    {
        if (isNull(root)) return true;
        return isBalanced(root);
    }
    /*2*/
    [[maybe_unused]] bool isPerfect()
    {
        if (isNull(root)) return true;
        return isPerfect(root);
    }

};