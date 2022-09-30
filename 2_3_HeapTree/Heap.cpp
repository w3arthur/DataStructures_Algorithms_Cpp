//Fix needToSwap function
//Delete vector version
#pragma once
#include <iostream>
#include <string>
//move to smart pointer
//move to string_view to print
//fix destructures!     List.root   List.last
//delete in the middle
using std::string, std::to_string, std::exception, std::cout;
class Heap {
private:
    int count;
    int* itemArray;
    int arrayLength;
    void swap(int& a, int b) const { swap(itemArray[a], itemArray[b]); }
    static int parent(int& index) {return index / 2;} // index/2
    static int child(int& index) {return index * 2;} // index*2
    static int left(int& index) { return  child(index) + 1; } // index*2+1
    static int right(int& index) { return  child(index) + 2; } // index*2+2
    void bubbleUp() const
    {
        auto index = count - 1; //last
        while (index > 0 && itemArray[index] > itemArray[parent(index)])
        {
            swap(itemArray[index], itemArray[parent(index)]);
            index = parent(index);
        }
    }

    void bubbleDown()  // לחזור!
    {
        int index{};
        while (index <= count && !isValidParent(index))
        {
            int largerIndex = largerChildIndex(index);
            swap(itemArray[index], itemArray[largerIndex]);
            index = largerIndex;
        }
    }

    bool hasLeftChild(int& i) const { return left(i) <= count; }
    bool hasRightChild(int& i) const { return right(i) <= count; }
    int largerChildIndex(int& index) const
    {
        if (hasLeftChild(index) && hasRightChild(index))
        {
            if (itemArray[left(index)] > itemArray[right(index)]) return left(index);
            else return right(index);
        }
        else if (hasLeftChild(index) && !hasRightChild(index)) return left(index);
        else return index;
    }
    bool isValidParent(int& index) const
    {
        auto isValidLeft = itemArray[index] >= itemArray[left(index)];
        auto isValidRight = itemArray[index] >= itemArray[right(index)];
        if (hasLeftChild(index) && hasRightChild(index)) return isValidLeft && isValidRight;
        if (hasLeftChild(index) && !hasRightChild(index)) return isValidLeft;
        /*if (!hasLeftChild(index))*/  return true;
    }

public:
    explicit Heap() : arrayLength{20}, itemArray{new int[arrayLength]}, count{} {}
    ~Heap() { delete[](itemArray); }
    [[nodiscard]] bool isFull() const { return count == arrayLength; }
    [[nodiscard]] bool isEmpty() const { return count == 0; }
    void insert(const int data)
    {
        if(isFull()) throw exception(); //or extend
        itemArray[count] = data;
        count ++;
        bubbleUp();
    }
    [[nodiscard]] int max() const
    {
        if (isEmpty()) throw exception();
        return itemArray[0];    //root
    }
    int remove() //remove top
    {
        if (isEmpty()) throw exception();
        int temp = itemArray[0];
        count--;
        itemArray[0] = itemArray[count];
        bubbleDown();
        return temp;
    }
    [[nodiscard]] string print() const {
        string str{};
        for(int i{}; i < count; i++) str += to_string(itemArray[i]) + ", ";
        str += "\n";
        return str;
    }
};