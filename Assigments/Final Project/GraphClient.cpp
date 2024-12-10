#include "Graph.h"
#include <iostream>
#include "Graph.cpp"

using namespace std;

int main() {
    Graph isaiahgraph;
    isaiahgraph.add_vertex();
    isaiahgraph.add_vertex();
    isaiahgraph.add_vertex();
    isaiahgraph.add_vertex();
    isaiahgraph.add_vertex();
    isaiahgraph.add_vertex();
    isaiahgraph.add_edge(0, 2);
    isaiahgraph.add_edge(2, 4);
    isaiahgraph.add_edge(2, 5);
    isaiahgraph.add_edge(4, 5);
    isaiahgraph.add_edge(4, 3);
    isaiahgraph.add_edge(5, 3);
    isaiahgraph.add_edge(3, 1);

    cout << isaiahgraph << endl;

    return 0;
}
// Question set 1 The representation of the graph is a adjacency list. The adjancey list is being stored as a set 
// Question set 2 The nedges also keeps track of the number of vertices in the graph as well
 