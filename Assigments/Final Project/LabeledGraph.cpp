#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "LabeledGraph.h"

using namespace std;

void LabeledGraph::add_vertex(string vlabel){
  labels.push_back(vlabel);
  indexedLabels.insert(pair<string, int>(vlabel, V()));
  set<int> s;
  vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target){
    if (!contains(source))
      add_vertex(source);
    if (!contains(target))
      add_vertex(target);
    vertices[indexedLabels[source]].insert(indexedLabels[target]);
    vertices[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
  return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const{
    return vertices[v];
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    return indexedLabels[vlabel];
}

ostream& operator<< (ostream &out, const LabeledGraph &g) {
    out << "======================================" << endl;
    out << "Graph Summary: " << g.V() << " vertices , " << g.E() << " edges." << endl;
    out << "======================================" << endl;
    for (int i = 0; i < g.V(); i++) {
        out << g.label(i) << endl<<"     ";
        for (int v : g.neighbors(i)) {
            out << g.label(v) << endl << "     ";
        }
        out << endl;
    }
    return out;
}