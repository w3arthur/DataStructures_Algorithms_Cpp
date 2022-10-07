
//FIX Heap 2 vector fo Visual Studio
#include <iostream>
#include <list>
#include "Heap.cpp"
#include "HeapVector.cpp"
using  std::cout, std::endl;
int main() {
    cout << "HeapTree (please fix!!!)1212" << endl;

    Heap heap{};
    
    heap.insert(2);
    heap.insert(20);
    heap.insert(10);
    heap.insert(50); // will remove
    heap.insert(6);
    heap.insert(26); // will remove
    cout <<  heap.remove() << endl;
    cout <<  heap.remove() << endl;
    cout << heap.print() << endl;

    cout << endl << "Heap2 (Vector)" << endl;
    HeapVector heap2{};     //To fix removing and bubble down  !!!

    heap2.insert(20);
    heap2.insert(10);
    heap2.insert(5);
    heap2.insert(2);

    //to fix !!!! remove() and shiftDown
    cout <<  heap2.extractMax() << endl;
    cout <<  heap2.extractMax() << endl;    //WRONG !!!

    cout << heap2.print() << endl;

    return EXIT_SUCCESS;
}











[[maybe_unused]] int getKthLargest (const int* array, const int& arrayLength,const int& kth)
{
    if (kth > arrayLength || kth < 1) throw std::exception();
    Heap heap{};
    for (int i{}; i < arrayLength; ++i) heap.insert(array[i]);
    for (int i = 0; i < kth - 1; i++) heap.remove();
    return heap.max();//heap.Remove();
}

void arrayHeapify (const int* array, const int& arrayCount) { for (int i = arrayCount / 2 - 1; i >= 0; i--) arrayHeapify(array, i); }

[[maybe_unused]] void arrayHeapify (int* array, const int& arrayCount,  const int& i)
{
    auto largerIndex = i;
    auto leftIndex = (i << 1)  + 1; //i*2+1
    auto rightIndex = (i << 1) + 2; //i*2+2
    if (leftIndex < arrayCount && array[leftIndex] > array[largerIndex]) largerIndex = leftIndex;
    if (rightIndex < arrayCount && array[rightIndex] > array[largerIndex]) largerIndex = rightIndex;
    if (i == largerIndex) return;
    std::swap(array[i], array[largerIndex]);
}

