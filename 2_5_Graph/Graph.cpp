#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <memory>
#include <iterator>
using std::string, std::to_string, std::cout, std::map, std::pair, std::set;
using std::stack, std::queue, std::list, std::shared_ptr, std::make_shared, std::exception;

class Graph {   //for example only
    struct Node {
     char label;
     explicit Node(char& label) : label{label} {   }
     ~Node(){cout << "del:" << label << " ";}
     bool operator<(const struct Node& other) const { return this->label < other.label; }
     [[nodiscard]] char print() const { return label; }
    };

    typedef shared_ptr<struct Node> sp_Node;
    //typedef std::_Rb_tree_iterator<pair<const char, sp_Node>> it_Node;

    map<char, sp_Node> nodes;
    map<sp_Node, list<sp_Node>> edges;
    bool isNull(auto itnode) { return itnode == nodes.end();}
    void traverseDepthFirst_recursion(sp_Node& node, set<sp_Node>& visited)
    {
        cout << node->print() << " ";
        visited.insert(node);
        for (auto neighbour : edges.find(node)->second)
        if (!(visited.find(neighbour) != visited.end())) traverseDepthFirst_recursion(neighbour, visited);
    }

    [[maybe_unused]] static list<char> toList(stack<sp_Node>& stack) {   //fix to insert with it
        list<char> sortedList{};
        while (stack.empty()) {sortedList.push_back(stack.top()->label); stack.pop();}
        return sortedList;
    }
    void topologicalSort(const sp_Node& node, set<sp_Node> visitedSet, stack<sp_Node> stack)
    {
        if (visitedSet.find(node) != visitedSet.end()) return;
        visitedSet.insert(node);
        for (const auto& neighbour : edges.find(node)->second)
            topologicalSort(neighbour, visitedSet, stack);
        stack.push(node);
    }
    bool hasCycle(const sp_Node& node, set<sp_Node> all, set<sp_Node> visiting, set<sp_Node> visited)
    {
        all.erase(node);
        visiting.insert(node);
        for (const auto& neighbour : edges.find(node)->second)
        {
            if (visited.find(neighbour) != visited.end()) continue;
            if (visiting.find(neighbour) != visiting.end()) return true;
            if (hasCycle(neighbour, all, visiting, visited)) return true;
        }
        visiting.erase(node);
        visited.insert(node);
        return false;
    }
public:
    explicit Graph() : nodes{}, edges{} {}
    ~Graph() = default;
    void addNode(char label)
    {
        auto newNode= make_shared<Node>(label);
        nodes.insert({label, newNode});
        auto node = nodes.find(label)->second;
        list<sp_Node> newNodeList{};
        edges.insert({node, newNodeList});  //new List
    }
    void removeNode(char label)
    {
        auto it = nodes.find(label);
        if ( !(it == nodes.end()) ) return;
        nodes.erase(label);
        edges.erase( it->second );
    }

    void addEdge(char from, char to)
    {   //relationship from -> to

        try
        {
            if(nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) throw exception();
            edges.find(nodes.find(from)->second)->second.push_back(nodes.find(to)->second);
        } catch (...) { throw exception(); }    //IsNull
    }

    [[maybe_unused]] void removeEdge(char from, char to)
    {   //remove from.to
        try {edges.find(nodes.find(from)->second)->second.remove(nodes.find(to)->second);}
        catch (...) { return; }    //IsNull
    }



    //Iteration
    [[maybe_unused]] void traverseDepthFirst(char root)
    {
        set<sp_Node> visited{};
        stack<sp_Node> stack{};
        auto rootNode = nodes.find(root);
        if (isNull(rootNode)) return;
        stack.push(rootNode->second);   //Link
        while (stack.empty())
        {
            auto node = stack.top() ;
            stack.pop();
            if (visited.find(node) != visited.end()) continue;
            else visited.insert(node);
            cout << node << " ";
            for (const auto& neighbour : edges.find(node)->second)   //Links
                if (!(visited.find(neighbour) != visited.end())) stack.push(neighbour);
        }
    }

    [[maybe_unused]] void traverseBreadthFirst(char root)
    {
        set<sp_Node> visited{};
        queue<sp_Node> queue{};
        auto rootNode = nodes.find(root);
        if (isNull(rootNode)) return;
        queue.push(rootNode->second);   //Link
        while (queue.empty())
        {
            auto node = queue.front() ;
            queue.pop();
            if (visited.find(node) != visited.end()) continue;
            else visited.insert(node);
            cout << node << " ";
            for (const auto& neighbour : edges.find(node)->second)   //Links
                if (!(visited.find(neighbour) != visited.end())) queue.push(neighbour);
        }
    }

    [[maybe_unused]] void traverseDepthFirst_recursion(char root)
    {
        try
        {
            set<sp_Node> visited{};
            auto rootNode = nodes.find(root)->second;
            traverseDepthFirst_recursion(rootNode, visited);
            cout << "\n";
        } catch (...) { return; }
    }

    bool hasCycle()
    {   //לחזור
        set<sp_Node> allNodes{};
                for(const auto& it : nodes) { allNodes.insert(it.second);}
        set<sp_Node> visiting{};
        set<sp_Node> visited{};
        for(const auto& current : allNodes)  if (hasCycle(current, allNodes, visiting, visited)) return true;
        return false;
    }


    string print()
    {
        string str{};
        for (const auto& itMap : edges)
        {
            auto targets = edges.find(itMap.first)->second;
            if (!targets.empty()) {
                str += itMap.first->print();
                str += " is connected to [";
                for(const auto& itList: targets) {
                    if(itList == nullptr) continue;
                    str += itList->print();
                    str +=  ", ";
                }
                str += "]\n";
            }
        }
        return str;
    }

};