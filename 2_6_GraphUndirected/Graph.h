// to add remove node
// to add remove edge

//fix!!!  getMinimumSpanningTree
//fix!!!    priority queue issue and comparing function
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <memory>

using std::string, std::to_string, std::cout, std::map, std::pair, std::set, std::list, std::vector;
using std::stack, std::queue, std::priority_queue, std::shared_ptr, std::weak_ptr, std::make_shared, std::exception;

struct Node
{
    typedef shared_ptr<struct Node> sp_Node;
    typedef shared_ptr<struct Edge> sp_Edge;
    char label;
    list<sp_Edge> edges; /*!*/
    explicit Node(char& label) : label{label}, edges{} {   }
    ~Node(){ cout << "del:" << label << "; "; }
    void addEdge(sp_Node& to, int weight) /*!*/
    {
        auto newEdge = make_shared<Edge>(this, to, weight);
        edges.push_back(newEdge);
    }
    [[nodiscard]] string print() const { string toString{}; return toString+label; }
};
struct Edge {
    typedef weak_ptr<struct Node> wp_Node;
    typedef shared_ptr<struct Node> sp_Node;
    typedef Node* ptr_Node; //cant use wp_ (weak pointer) on this
    int weight;
    ptr_Node from;
    wp_Node to;
    explicit Edge(Node* from, sp_Node& to, int weight) : from{from}, to{to}, weight{weight} {   }
    ~Edge(){ cout << "del:" << print() << "; "; }
    [[nodiscard]] sp_Node getTo() const { return sp_Node(to); }
 //   /*!*/ bool operator<(const struct Edge &other) const { return this->weight > other.weight; } /*!*/
    [[nodiscard]] string print() const {return from->print() + ">" + (!to.expired() ? getTo()->print() : "*") + "(" + to_string(weight) + ")";}
};
struct NodePriority {
    typedef std::shared_ptr<struct Node> sp_Node;
    sp_Node node;
    int priority;
    explicit NodePriority(sp_Node node, int priority) : node{std::move(node)}, priority{priority} {}
    ~NodePriority() { cout << "delQPN:" << "" + node->print() << "; "; }
   // /*!*/ bool operator<(const struct NodePriority &other) const { return this->priority < other.priority; } /*!*/
};

class Graph {   //for example only
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
    explicit Graph() : nodes{} {}

    ~Graph() = default;

    void addNode(char label);

    void addEdge(char from, char to, int weight) const;

    [[nodiscard]] list<char> getShortestPath(char from, char to) const;

    bool hasCycle();

    bool containsNode(char label);

    Graph getMinimumSpanningTree(); //to check

    [[nodiscard]] string print() const;

};
