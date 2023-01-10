// to add remove node
// to add remove edge

//fix!!!  getMinimumSpanningTree
//fix!!!    priority queue issue and comparing function

#pragma once
#include "Node_Edge.h"
#include <vector>
#include <stack>
#include <map>
using std::stack, std::map, std::pair, std::set, std::vector, std::exception;



class GraphWheight {   //for example only
    typedef shared_ptr<struct Node> sp_Node;
    typedef shared_ptr<struct Edge> sp_Edge;
    typedef shared_ptr<struct NodePriority> sp_NodePriority;
    //typedef std::_Rb_tree_const_iterator<pair<const char, sp_Node>> it_Node;

    map<char, sp_Node> nodes;

    static list<char> buildPath(map<sp_Node, sp_Node>& previousNodes, const sp_Node& toNode);

    static list<char> toList(stack<sp_Node> &stack);

    bool hasCycle(const sp_Node& node, const sp_Node& parent, set<sp_Node>& visited) const;

    [[nodiscard]] bool containsNode(const sp_Node& node) const;


public:
    explicit GraphWheight() : nodes{} {}

    ~GraphWheight() = default;

    void addNode(char label);

    void addEdge(char from, char to, int weight) const;

    [[nodiscard]] list<char> getShortestPath(char from, char to) const;

    bool hasCycle();

    bool containsNode(char label);

    GraphWheight getMinimumSpanningTree(); //to check

    [[nodiscard]] string print() const;

};
