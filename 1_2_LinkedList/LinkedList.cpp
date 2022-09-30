#pragma once
#include <iostream>
#include <string>
//move to smart pointer
//move to string_view to print
//fix destructures!     List.root   List.last
//delete in the middle
using std::string, std::to_string, std::cout, std::exception;
class List
{
private:
    struct Node
    {
        int data;
        struct Node* next;
        explicit Node(int data) : data{data}, next{nullptr} { }
        ~Node(){ cout << "del:" << data << "; "; }
    };
    struct Node* root;
    struct Node* last;
    int count;
    bool isReversed;
    [[nodiscard]] bool isEmpty() const { return root == nullptr; }
    void resetList(){ delete root; root=nullptr; last=nullptr; }
public:
    explicit List() : root{nullptr}, last{nullptr}, count{}, isReversed{false} { }
    ~List(){ while(root != nullptr && !isReversed) {removeLast();} }
    void insertLast(int data)
    {
        Node* node = new Node( data );
        if (isEmpty()) { root = node; last = node; }
        else { last->next = node; last = node; }
        count++;
    }
    void insertFirst(int data)
    {
        Node* node = new Node( data );
        if (isEmpty()) { root = node; last = node; }
        else { node->next = root; root = node; }
        count ++;
    }

    [[maybe_unused]] int removeFirst()
    {
        if (isEmpty()) throw exception();
        int value = root->data;
        if (root == last) { resetList();return value;}
        Node *current = root;
        root = root->next;
        delete current;
        count --;
        return value;
    }
    int removeLast()
    {
        if (isEmpty()) throw exception();
        int value = last->data;
        if (root == last) { resetList();return value;}

        Node* current = root->next;
        Node* previous = root;
        while (current->next != nullptr)
        {
            previous = previous->next;
            current = current->next;
        }
        previous->next = nullptr;
        last = previous;
        delete current;
        count --;
        return value;
    }

    int kth(int subPlace){
        if(isEmpty()) throw exception();
        if(subPlace > count || subPlace <= 0) throw exception();
        Node* kth = root;
        Node* current = root;
        for (int i{}; i < subPlace - 1; ++i) current = current->next;
        while (current != last)
        {
            current = current->next;
            kth = kth->next;
        }
        return kth->data;
    }

    void reverse(){
        if(isEmpty()) return;
        List* newList = new List();
        //List* newList = &list;
        Node* current = root;
        while (current != nullptr)
        {
            newList->insertFirst(current->data);
            current = current->next;
        }
        this->root = newList->root;
        this->last = newList->last;
        newList->isReversed = true;
        delete newList;
    }
    [[nodiscard]] string print() const
    {
        Node* current = root;
        string str{};
        while (current != nullptr)
        {
            str += to_string(current->data) + ", ";
            current = current->next;
        }
        str += "\n";
        return str;
    }
};