//Fix needToSwap function
//Delete vector version

#include <iostream>
#include <string>
//move to smart pointer
//move to string_view to print
//fix destructures!     List.root   List.last
//delete in the middle
using std::string, std::to_string, std::cout, std::swap, std::exception;
class Heap {
    int count;
    int* itemArray;
    int arrayLength;
    static int parent(int index); // index/2
    static int child(int index); // index*2
    static int left(int index); // index*2+1
    static int right(int index); // index*2+2
    void bubbleUp() const;

    void bubbleDown();  // לחזור!

    bool hasLeftChild(int i) const;
    bool hasRightChild(int i) const;

    int largerChildIndex(int index) const;

    bool isValidParent(int index) const;

public:
    explicit Heap() : arrayLength{ 20 }, itemArray{ new int[20] }, count{} {}
    ~Heap() { delete[](itemArray); }
    [[nodiscard]] bool isFull() const;
    [[nodiscard]] bool isEmpty() const;
    void insert(int data);
    [[nodiscard]] int max() const;
    int remove(); //remove top

    [[nodiscard]] string print() const;
};