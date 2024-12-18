#ifndef LABELED_GRAPH_H
#define LABELED_GRAPH_H

#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

class LabeledGraph {
public:

    LabeledGraph() { nedges = 0; }
    LabeledGraph(const std::string &filename);  // Constructor to build the graph from an input file

    // MODIFICATION MEMBER FUNCTIONS
    //adds a vertex with a specifc label
    void add_vertex(std::string vlabel);

    //adds an edge from vertex with source label to vertex with target label
    void add_edge(std::string source, std::string target);

    // CONSTANT MEMBER FUNCTIONS
    int V( ) const { return vertices.size(); } //number of vertices
    int E( ) const { return nedges; }       //number of edges
    bool contains(std::string vlabel) const;     //does graph contain vertex with label vlabel?
    std::set<int> neighbors(int v) const;  //returns the vertices adjacent to vertex v
    std::string label(int v) const;     //returns the label of vertex v
    int index(std::string vlabel);           //returns the index of the vertex with label vlabel
    std::vector<std::string> find_neighbors(const std::string &artist) const; // finds neighbors of a given artist

      // BFS function to find shortest paths from a source vertex
    std::map<int, int> BFS(int v);

    // Function to return the path from the source vertex to a specific target vertex
    std::vector<int> pathTo(const std::map<int, int> &parent_map, int target);


    // OVERLOADED OUTPUT OPERATOR
    friend std::ostream& operator<< (std::ostream &out, const LabeledGraph &g);

private:
  int nedges;
  std::vector<std::set<int> > vertices;
  std::vector<std::string> labels;
  std::map<std::string, int> indexedLabels;
};

#endif
