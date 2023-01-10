#pragma once
#include <iostream>
#include <string>
#include <set>

#include <list>
#include <memory>
#include <queue>
#include <utility>

using std::string, std::to_string, std::queue, std::priority_queue, std::cout;
using std::list, std::make_shared, std::shared_ptr, std::weak_ptr;

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