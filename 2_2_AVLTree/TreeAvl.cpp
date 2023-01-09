#include "TreeAvl.h"
bool TreeAvl::isNull(const Node *node) { return node == nullptr; }

bool TreeAvl::isLeaf(const Node *node) {
    return isNull(node->left) && isNull(node->right);
}

int TreeAvl::getHeight(Node *node) {
    return isNull(node) ? -1 : node->height;
}

int TreeAvl::getMaxHeight(Node *node) {
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

int TreeAvl::balanceFactor(Node *node) {
    return isNull(node) ? 0 : getHeight(node->left) - getHeight(node->right);
}

Node *TreeAvl::insert(int value, Node *node, Node *newNode) const {
    if (isNull(node)) node = newNode;
    else if (value < node->data) node->left =  insert(value, node->left, newNode);
    else if (value > node->data) node->right =  insert(value, node->right, newNode);
    else throw exception();
    node->height = getMaxHeight(node); // for balancing

    return balance(node); //node;
}

Node *TreeAvl::balance(Node *node) {
    if (balanceFactor(node) > 1)    // RR
    {
        if (balanceFactor(node->left) < 0) /*LR*/ { node->left = rotateLeft(node);}
        return rotateRight(node);   /*RR*/
    }
    else if (balanceFactor(node) < -1) //LL
    {
        if (balanceFactor(node->right) > 0) /*RL*/ { node->right = rotateRight(node);}
        return rotateLeft(node);    /*LL*/
    }
    else return node;   // balance ok -1 <=> 1
}

Node *TreeAvl::rotateLeft(Node *node) {
    //maybe new root
    auto* topNode = node->right;
    node->right = topNode->left;
    topNode->left = node;
    node->height = getMaxHeight(node);
    topNode->height = getMaxHeight(topNode);
    return topNode;
    // 10		  20
    //  20	=>	10  30
    //   30
}

Node *TreeAvl::rotateRight(Node *node) {
    //maybe new root
    auto* topNode = node->left;
    node->left = topNode->right; // node.ChildLeft.ChildRight;
    topNode->right = node;
    node->height = getMaxHeight(node);
    topNode->height = getMaxHeight(topNode);
    return topNode;
    //   30		  20
    //  20	=>	10  30
    // 10
}

int TreeAvl::height(Node *node) const {
    if (isNull(node)) return INT_MIN;//-1;
    if (isLeaf(node)) return 0; // base condition
    return 1 + std::max(height(node->left), height(node->right));
}

void TreeAvl::getNodesAtDistance(Node *node, int distance, list<int> *list) const {
    if (isNull(node)) return;
    if (distance == 0) { list->push_back(node->data); return; }
    getNodesAtDistance(node->left, distance - 1, list);
    getNodesAtDistance(node->right, distance - 1, list);
}

bool TreeAvl::isPerfect(Node *node) const {
    if (isNull(node)) return true;
    if (isNull(node->left) && !isNull(node->right) || !isNull(node->right) && isNull(node->left)) return false;
    return isPerfect(node->left) && isPerfect(node->right);
}

void TreeAvl::insert(int data) {
    Node* node = new Node( data );
    if(isNull(root)) {root = node; return;}
    root = insert(data, root, node);
}

int TreeAvl::height() { return height(root); }

list<int> TreeAvl::getNodesAtDistance(int distance) {
    list<int> list{};
    getNodesAtDistance(root, distance, &list);
    return list;
}

string TreeAvl::traverseLevelOrder() {
    string str{};
    for (int i{}; i <= height(); i++) {
        str += to_string(i) + "| ";
        for (auto data: getNodesAtDistance(i))
            str += to_string(data) + ", ";
        str += "\n";
    }
    return str;
}

string TreeAvl::print() { return traverseLevelOrder(); }

bool TreeAvl::isBalanced() { return abs(balanceFactor(root)) <= 1; }

bool TreeAvl::isPerfect() { return isPerfect(root); }
