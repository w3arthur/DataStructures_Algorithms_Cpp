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
using std::stack, std::queue, std::priority_queue, std::shared_ptr, std::make_shared, std::exception;

struct Node
{
    typedef std::shared_ptr<struct Node> sp_Node;
    typedef std::shared_ptr<struct Edge> sp_Edge;
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
    typedef std::weak_ptr<struct Node> wp_Node;
    typedef std::shared_ptr<struct Node> sp_Node;
    int weight;
    Node* from;
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
private:
    typedef std::shared_ptr<struct Node> sp_Node;
    typedef std::shared_ptr<struct Edge> sp_Edge;
    typedef shared_ptr<struct NodePriority> sp_NodePriority;
    //typedef std::_Rb_tree_const_iterator<pair<const char, sp_Node>> it_Node;
    map<char, sp_Node> nodes;

    list<char> buildPath(map<sp_Node, sp_Node>& previousNodes, const sp_Node& toNode) const {
        stack<sp_Node> stack{};
        stack.push(toNode);
        auto previous = previousNodes.find(toNode)->second;
        while (true)
        {
            stack.push(previous);
            if (previousNodes.find(previous) == previousNodes.end()) break;
            previous = previousNodes.find(previous)->second;
        }
        return toList(stack);
    }
    static list<char> toList(stack<sp_Node> &stack) {   //fix to insert with it
        list<char> sortedList{};
        while (!stack.empty()) { sortedList.push_back(stack.top()->label); stack.pop(); }
        return sortedList;
    }
    bool hasCycle(const sp_Node& node, const sp_Node& parent, set<sp_Node>& visited) const
    {
        visited.insert(node);
        for (auto& edge : node->edges)
        {
            auto edgeTo = edge->getTo();
            if (edgeTo == parent) continue;
            if (visited.find(edgeTo) != visited.end()
                || hasCycle(edgeTo, node, visited)) return true;
        }
        return false;
    }


    bool containsNode(const sp_Node& node) const { return !(nodes.find(node->label) == nodes.end()); }


public:

    explicit Graph() : nodes{} {}
    ~Graph() = default;
    void addNode(char label)
    {
        auto newNode = make_shared<Node>(label);
        nodes.insert({label, newNode});
    }



    void addEdge(char from, char to, int weight) const
    { // relationship
        if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) throw exception();
        auto fromNode = nodes.find(from)->second;
        auto toNode = nodes.find(to)->second;
        fromNode->addEdge(toNode, weight);
        toNode->addEdge(fromNode, weight);
    }
    list<char> getShortestPath(char from, char to) const
    {
        if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) throw exception();
        auto fromNode = nodes.find(from)->second;
        auto toNode = nodes.find(to)->second;
        map<sp_Node, int> distances{};
        for (auto& node: nodes) distances.insert({node.second, INT_MAX});
        distances[fromNode] = 0;//.insert({fromNode, 0}); // java: replace(,) // A 0
        map<sp_Node, sp_Node> previousNodes{};
        set<sp_Node> visited{};
        priority_queue<sp_NodePriority> queue{}; //java: PriorityQueue<NodeEntry> queue = new PriorityQueue<>(Comparator.comparingInt(ne->ne.priority));
        // priority_queue<int, list<int>, std::greater<int>> a{};
        queue.push(make_shared<NodePriority>(fromNode, 0)); // only item in the queue
        while (!queue.empty()) {
            auto current = queue.top();
            queue.pop();
            visited.insert(current->node);
            for (auto& edge: current->node->edges) {
                auto edgeToNode = edge->getTo();
                if (visited.find(edgeToNode) != visited.end()) continue;
                /*!*/   int newDistance = distances.find(current->node)->second + edge->weight;
                if (newDistance < distances.find(edgeToNode)->second)
                {
                    distances[edgeToNode] = newDistance; // java: replace(,)
                    previousNodes.insert({edgeToNode, current->node});
                    queue.push(make_shared<NodePriority>(edgeToNode, newDistance));
                }
            }
        }
        //return distances.get(toNode);
        return buildPath(previousNodes, toNode);
    }
    bool hasCycle()
    {   // !!! Review
        set<sp_Node> visited{};
        for(auto& node : nodes)
            if (!(visited.find(node.second) != visited.end())
                && hasCycle(node.second, nullptr, visited)) return true;
        return false;
    }
    bool containsNode(char label) { return nodes.find(label) != nodes.end(); }



    Graph getMinimumSpanningTree() //to fix !!!
    {
        Graph tree{};
        if (nodes.empty()) return tree;
        priority_queue<sp_Edge> edges{};
        auto startNode = nodes.begin()->second; //java: nodes.values().iterator().next();
        for (auto& edge : startNode->edges) edges.push(edge);
        tree.addNode(startNode->label);
        if (edges.empty()) return tree;
        while (tree.nodes.size() < nodes.size())
        {
            auto minEdge = edges.top();
            edges.pop();
            auto nextNode = minEdge->getTo();
            if (tree.containsNode(nextNode->label)) continue;
            tree.addNode(nextNode->label);
            tree.addEdge(minEdge->from->label, nextNode->label, minEdge->weight);
            for (auto& edge : nextNode->edges)
            if (!tree.containsNode(edge->getTo())) edges.push(edge);
        }
        return tree;
    }

    [[nodiscard]] string print() const
    {
        string str{};
        for (auto& node: nodes) {
            auto targets = node.second->edges;// adjacencyList.get(source);
            str += node.second->print() += " is connected to [";
            if (!targets.empty()) for (auto& t: targets) str += t->print() += ", ";
            str += "]\n";
        }
        return str;
    }

};
