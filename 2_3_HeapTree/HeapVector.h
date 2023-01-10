#include <iostream>
#include <string>
#include <vector>

using std::string, std::to_string, std::cout, std::swap;
class HeapVector {
    int _size;
    std::vector<int> vector;
    int parent(int& i) const;    // i/2   //i >> 1
    int child(int& i) const;    // i*2    //i << 1
    int left(int& i) const; // index*2+1
    int right(int& i) const; // index*2+2
    void shiftDown(int i);
    void shiftUp(int i);
    bool hasLeftChild(int& i) const;
    bool hasRightChild(int& i) const;
    [[nodiscard]] int largerChildIndex(int i) const;
    bool isValidParent(int& i) const;

public:
    explicit HeapVector() : vector{}, _size{} {}  //set to NULL
    ~HeapVector() = default;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int getMax() const;
    void insert(const int& value);
    int extractMax(); //remove()

    [[nodiscard]] string print() const;
};