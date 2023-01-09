#pragma once
#include "Graph.h"

list<char> Graph::buildPath(map<sp_Node, sp_Node>& previousNodes, const sp_Node& toNode) {
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

list<char> Graph::toList(stack<sp_Node> &stack) {   //fix to insert with it
    list<char> sortedList{};
    while (!stack.empty()) { sortedList.push_back(stack.top()->label); stack.pop(); }
    return sortedList;
}

bool Graph::hasCycle(const sp_Node& node, const sp_Node& parent, set<sp_Node>& visited) const
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


bool Graph::containsNode(const sp_Node& node) const { return !(nodes.find(node->label) == nodes.end()); }



void Graph::addNode(char label)
{
    auto newNode = make_shared<Node>(label);
    nodes.insert({label, newNode});
}


void Graph::addEdge(char from, char to, int weight) const
{ // relationship
    if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) throw exception();
    auto fromNode = nodes.find(from)->second;
    auto toNode = nodes.find(to)->second;
    fromNode->addEdge(toNode, weight);
    toNode->addEdge(fromNode, weight);
}

list<char> Graph::getShortestPath(char from, char to) const
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

bool Graph::hasCycle()
{   // !!! Review
    set<sp_Node> visited{};
    for(auto& node : nodes)
        if (!(visited.find(node.second) != visited.end())
            && hasCycle(node.second, nullptr, visited)) return true;
    return false;
}

bool Graph::containsNode(char label) { return nodes.find(label) != nodes.end(); }

Graph Graph::getMinimumSpanningTree() //to check
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

string Graph::print() const
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

