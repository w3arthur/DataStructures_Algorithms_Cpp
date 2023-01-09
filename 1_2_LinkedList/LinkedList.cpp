#include "LinkedList.h"

bool List::isEmpty() const {
    return root == nullptr;
}

void List::insertLast(int data) {
    Node* node = new Node( data );
    if (isEmpty()) { root = node; last = node; }
    else { last->next = node; last = node; }
    count++;
}

void List::insertFirst(int data) {
    Node* node = new Node( data );
    if (isEmpty()) { root = node; last = node; }
    else { node->next = root; root = node; }
    count ++;
}

int List::removeFirst() {
    if (isEmpty()) throw exception();
    int value = root->data;
    if (root == last) { resetList();return value;}
    Node *current = root;
    root = root->next;
    delete current;
    count --;
    return value;
}

int List::removeLast() {
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

int List::kth(int subPlace) {
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

void List::reverse() {
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

string List::print() const {
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
