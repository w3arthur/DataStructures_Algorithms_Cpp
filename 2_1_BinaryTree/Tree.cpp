#include "Tree.h"
#include "../2_2_AVLTree/TreeAvl.h"


bool Tree::isNull(const Node *node) { return node == nullptr; }

bool Tree::isLeaf(const Node *node) {
    return isNull(node->left) && isNull(node->right);
}

int Tree::height(const Node *node) const {
    if(isNull(node)) return -1; //INT_MIN
    if(isLeaf(node)) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

int Tree::min(const Node *node) const {
    if(isNull(node)) return INT_MAX;
    if(isLeaf(node)) return node->data;
    auto left = min(node->left);
    auto right = min(node->right);
    return std::min(std::min(left, right), node->data);
}

bool Tree::equals(Node *a, Node *b) const {
    if(isNull(a) && isNull(b)) return true;
    if(!isNull(a) && !isNull(b))
        return
                a->data == b->data
                && equals(a->left, b->left)
                && equals(a->right, b->right);
    return false;
}

bool Tree::isBinarySearchTree(Node *node, int min, int max) const {
    if (isNull(node)) return true;
    if ( !(node->data >= min && node->data <= max) ) return false;
    return
            isBinarySearchTree(node->left, min, node->data)
            && isBinarySearchTree(node->right, node->data, max);
}

void Tree::getNodesAtDistance(Node *node, int distance, list<int> *list) const {
    if (isNull(node)) return;
    if (distance == 0) { list->push_back(node->data); /*System.out.print( node.value + " " );*/ return; }
    getNodesAtDistance(node->left, distance - 1, list);
    getNodesAtDistance(node->right, distance - 1, list);
}

int Tree::size(Node *node) const {
    if (isNull(node)) return 0;
    return
            1
            + (!isNull(node->left) ? size(node->left) : 0)
            + (!isNull(node->right) ? size(node->right) : 0);
}

int Tree::countLevels(Node *node, int level) const {
    if (isNull(node)) return level;
    return
            1
            + std::max(
                    countLevels(node->left, level)
                    , countLevels(node->right, level)
            );
}

int Tree::max(Node *node) const {
    if (isNull(node)) return INT_MIN;
    return std::max(
            isNull(node->left) ? node->data : max(node->left)
            , isNull(node->right) ? node->data : max(node->right)
    );
}

bool Tree::contains(Node *node, int &data) const {
    if (isNull(node)) return false;
    if (data == node->data) return true;
    return contains(node->left, data) || contains(node->right, data); //O(n)
}

void Tree::traversePreOrder(Node *node) const {
    if (isNull(node)) return;   //base condition
    cout << node->data << " ";
    traversePreOrder(node->left);
    traversePreOrder(node->right);
}

void Tree::traverseInOrder(Node *node) const {
    if (isNull(node)) return;   //base condition
    traverseInOrder(node->left);
    cout << node->data << " ";
    traverseInOrder(node->right);
}

void Tree::traversePostOrder(Node *node) const {
    if (isNull(node)) return;   //base condition
    traversePostOrder(node->left);
    traversePostOrder(node->right);
    cout << node->data << " "; //Root
}

void Tree::TraverseInOrder2(Node *node, list<int> *list) const {
    // from low to high  1 2 3 4 ...
    if (isNull(node)) return;   //base condition
    TraverseInOrder2(node->left, list);
    list->push_back(node->data);
    TraverseInOrder2(node->right, list);
}

bool Tree::isBalanced(Node *node) const {
    if (isNull(node)) return true;
    return abs(height(node->left) - height(node->right))  <= 1
           && isBalanced(node->left)
           && isBalanced(node->right);
}

bool Tree::isPerfect(Node *node) const {
    if (isNull(node)) return true;
    return height(node->left) - height(node->right) == 0
           && isPerfect(node->left)
           && isPerfect(node->right);
}

void Tree::insert(int data) {
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

bool Tree::find(int data) {
    auto* current = root;
    while(!isNull(current))
    {
        if(data == current->data) return true;
        current = data < current->data ? current->left : current->right;
    }
    return false;
}

int Tree::height() { return height(root); }

int Tree::min() { return min(root); }

int Tree::min_binarySearchTree() {
    if(isNull(root)) throw exception();
    auto* current = root;
    while(!isNull(current->left)) current = current->left;
    int data = current->data;
    return data;
}

bool Tree::equals(const Tree *other) {
    if(other == nullptr) return false;
    return equals(root, other->root);
}

bool Tree::isBinarySearchTree() {
    return isBinarySearchTree(root, INT_MIN, INT_MAX);
}

void Tree::swapRoot() {
    auto* temp = root->left; root->left= root->right; root->right = temp;
}

list<int> Tree::getNodesAtDistance(int distance) {
    list<int> list{};
    getNodesAtDistance(root, distance, &list); /*Console.WriteLine("");*/
    return list;
}

void Tree::traverseLevelOrder() {
    for (int i{}; i <= height(); ++i)
    {
        auto list = getNodesAtDistance(i);
        cout << i << "| ";
        for(auto data: list) cout << data << ", ";
        cout << "\n";
    }
}

int Tree::size() {
    return size(root);
}

int Tree::countLevels() {
    return countLevels(root, 0);
}

int Tree::max() {
    if (isNull(root)) throw exception();
    return std::max(max(root), root->data);
}

bool Tree::contains(int data) {
    return contains(root, data);
}

void Tree::traversePreOrder() {
    traversePreOrder(root);
    cout <<"\n";
}

void Tree::traverseInOrder() {
    traverseInOrder(root);
    cout <<"\n";
}

void Tree::traversePostOrder() {
    traversePostOrder(root);
    cout <<"\n";
}

int Tree::Size2() {
    list<int> list{};
    TraverseInOrder2(root, &list);
    int size = list.size();
    return size;
}

string Tree::print() {
    list<int> list{};
    TraverseInOrder2(root, &list);
    string str{};
    for(auto data: list){
        str += to_string(data) + ", ";
    }
    return str;
}

bool Tree::isBalanced() {
    if (isNull(root)) return true;
    return isBalanced(root);
}

bool Tree::isPerfect() {
    if (isNull(root)) return true;
    return isPerfect(root);
}
