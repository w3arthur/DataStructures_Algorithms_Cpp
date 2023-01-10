#include "Heap.h"

int Heap::parent(int index) { return index / 2; }

int Heap::child(int index) { return index * 2; }

int Heap::left(int index) { return  child(index) + 1; }

int Heap::right(int index) { return  child(index) + 2; }

void Heap::bubbleUp() const {
    auto index = count - 1; //last
    while (index > 0 && itemArray[index] > itemArray[parent(index)])
    {
        swap(itemArray[index], itemArray[parent(index)]);
        index = parent(index);
    }
}

void Heap::bubbleDown() {
    int index{};
    while (index <= count && !isValidParent(index))
    {
        int largerIndex = largerChildIndex(index);
        swap(itemArray[index], itemArray[largerIndex]);
        index = largerIndex;
    }
}

bool Heap::hasLeftChild(int i) const { return left(i) <= count; }

bool Heap::hasRightChild(int i) const { return right(i) <= count; }

int Heap::largerChildIndex(int index) const {
    if (hasLeftChild(index) && hasRightChild(index))
    {
        if (itemArray[left(index)] > itemArray[right(index)]) return left(index);
        else return right(index);
    }
    else if (hasLeftChild(index) && !hasRightChild(index)) return left(index);
    else return index;
}

bool Heap::isValidParent(int index) const {
    auto isValidLeft = itemArray[index] >= itemArray[left(index)];
    auto isValidRight = itemArray[index] >= itemArray[right(index)];
    if (hasLeftChild(index) && hasRightChild(index)) return isValidLeft && isValidRight;
    if (hasLeftChild(index) && !hasRightChild(index)) return isValidLeft;
    /*if (!hasLeftChild(index))*/  return true;
}

bool Heap::isFull() const { return count == arrayLength; }

bool Heap::isEmpty() const { return count == 0; }

void Heap::insert(int data) {
    if (isFull()) throw exception(); //or extend
    itemArray[count] = data;
    count++;
    bubbleUp();
}

int Heap::max() const {
    if (isEmpty()) throw exception();
    return itemArray[0];    //root
}

int Heap::remove() {
    if (isEmpty()) throw exception();
    int temp = itemArray[0];
    count--;
    itemArray[0] = itemArray[count];
    bubbleDown();
    return temp;
}

string Heap::print() const {
    string str{};
    for (int i{}; i < count; i++) str += to_string(itemArray[i]) + ", ";
    str += "\n";
    return str;
}
