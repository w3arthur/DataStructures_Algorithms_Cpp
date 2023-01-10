#pragma once
#include "Node.h"     //#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <memory>
#include <iterator>
using std::to_string, std::map, std::pair, std::set;
using std::stack, std::queue, std::list, std::shared_ptr, std::make_shared, std::exception;


class Graph {   //for example only
    typedef shared_ptr<struct Node> sp_Node;
    //typedef std::_Rb_tree_iterator<pair<const char, sp_Node>> it_Node;
    map<char, sp_Node> nodes;
    map<sp_Node, list<sp_Node>> edges;
    bool isNull(auto itnode);
    void traverseDepthFirst_recursion(sp_Node& node, set<sp_Node>& visited);

    [[maybe_unused]] static list<char> toList(stack<sp_Node>& stack);
    void topologicalSort(const sp_Node& node, set<sp_Node> visitedSet, stack<sp_Node> stack);
    bool hasCycle(const sp_Node& node, set<sp_Node> all, set<sp_Node> visiting, set<sp_Node> visited);
public:
    explicit Graph() : nodes{}, edges{} {}
    ~Graph() = default;
    void addNode(char label);
    void removeNode(char label);

    void addEdge(char from, char to);

    [[maybe_unused]] void removeEdge(char from, char to)
    {   //remove from.to
        try {edges.find(nodes.find(from)->second)->second.remove(nodes.find(to)->second);}
        catch (...) { return; }    //IsNull
    }

    //Iteration
    [[maybe_unused]] void traverseDepthFirst(char root);

    [[maybe_unused]] void traverseBreadthFirst(char root);

    [[maybe_unused]] void traverseDepthFirst_recursion(char root);

    bool hasCycle();

    string print();

};