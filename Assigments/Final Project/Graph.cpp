
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <cassert>

using namespace std;

//Adds a vertex to the graph
//The index of the new vertex is automatically assigned
//O(v)
void Graph::add_vertex(){
  set<int> s;
  edges.push_back(s);

}
// Adds a new vertex to the graph and edges are stacked on top of each other


//Adds an edge connecting source to target
//O(v^2)
void Graph::add_edge(int source, int target){
    assert (contains(source) && contains(target));
    edges[source].insert(target);
    edges[target].insert(source);
    nedges++;
}
// Adds an edge to the graph. It takes two integers as parameters and adds an edge between the two vertices. It also increments the number of edges in the graph

//Returns number of vertices
//O(1)
int Graph::V( ) const { 
	return edges.size(); 
} 
//Returns the length of the edges vector which is the number of vertices in the graph

//Returns number of edges
//O(1)
int Graph::E( ) const { 
	return nedges; 
} 

//Returns the vertices adjacent to vertex v
//O(V^2)
set<int> Graph::neighbors(int v) const{
    assert (contains(v));
    return edges[v];
}
// Returns the set of vertices that are adjacent to the vertex v. It takes an integer as a parameter and returns a set of integers that are adjacent to the vertex v

//Checks if vertex v is in the graph
//O(V)
bool Graph::contains(int v) const{
  return v < V();
}
// Checks if the vertex v is in the graph. It takes an integer as a parameter and returns a boolean value

//O(V^2 + E)
ostream& operator<< (ostream &out, const Graph &g) {
  out << "======================================" << endl;
  out << "Graph Summary: " << g.V() << " vertices , " << g.E() << " edges." << endl;
  out << "======================================" << endl;
    for (int i = 0; i < g.V(); i++) {
        out << i << " --> ";
        for (int v : g.neighbors(i)) {
            out << v << "  ";
        }
        out << endl;
    }
  return out;
}
// Overloads the << operator to print the graph. It takes an ostream and a graph as parameters and returns an ostream. 
//It prints the number of vertices and edges in the graph and the vertices that are adjacent to each vertex
