//fix the issue with too much destructures

#include <iostream>
#include "Graph.cpp"
using  std::cout, std::endl, std::list;
int main() {

    cout << "Graph\n";   //retrieval
    {
        Graph graph1{};
        graph1.addNode('a');
        graph1.addNode('b');
        graph1.addNode('c');
        graph1.addEdge('a', 'b', 3);
         graph1.addEdge('a', 'c', 6);
        graph1.addEdge('b', 'c', 6);
        cout << graph1.print() << endl;

        cout << graph1.hasCycle() << endl;

        Graph graph2{};
        graph2.addNode('a');
        graph2.addNode('b');
        graph2.addNode('c');
        graph2.addEdge('a', 'b', 1);
        graph2.addEdge('b', 'c', 2);
        graph2.addEdge('b', 'c', 10);
        auto path = graph2.getShortestPath('a', 'c');
        cout << endl;
        for(auto node : path) cout << node << ", "; // a, b, c
        cout << endl << endl << endl << endl;

        Graph graph{};  //to fix !
        graph.addNode('a');
        graph.addNode('b');
        graph.addNode('c');
        graph.addNode('d');
        graph.addEdge('a', 'b', 3);
        graph.addEdge('b', 'd', 4);
        graph.addEdge('c', 'd', 5);
        graph.addEdge('a', 'c', 1);
        graph.addEdge('b', 'c', 2);
        auto tree = graph.getMinimumSpanningTree();
        cout << "Get Minimum Spanning Tree:" << endl;
        cout << tree.print() << endl << endl;
    }

    return EXIT_SUCCESS;
}