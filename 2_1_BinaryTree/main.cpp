

#include <iostream>
#include "Tree.cpp"
using  std::cout, std::endl;
int main() {
    cout << "BinaryTree" << endl;
    Tree tree{};
    tree.insert(5);
    tree.insert(10);
    tree.insert(20);
    tree.insert(2);

    Tree tree2{};
    tree2.insert(5);
    tree2.insert(10);
    tree2.insert(20);
    tree2.insert(435643);

    cout << "height: " << tree.height() << endl;
    cout << "min tree: "  << tree.min() << endl;
    cout << "min binary tree: " <<tree.min_binarySearchTree() << endl;
    cout << "equals: " << tree.equals(&tree2) << endl;
    for(auto data: tree.getNodesAtDistance(1)) cout << data << ", ";
    cout << endl << endl;
    tree.traverseLevelOrder();
    cout << "print: " << tree.print() << endl;
    cout << endl;
    cout << "end" << endl;

    return 0;
}