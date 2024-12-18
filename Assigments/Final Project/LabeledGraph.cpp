#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "LabeledGraph.h"
#include <queue>

using namespace std;

LabeledGraph::LabeledGraph(const std::string &filename) {
    nedges = 0;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string source, target;
        if (std::getline(iss, source, ',') && std::getline(iss, target, ',')) {
            add_edge(source, target);
        }
    }

    file.close();
}

void LabeledGraph::add_vertex(string vlabel){
    labels.push_back(vlabel);
    indexedLabels.insert({vlabel, V()});
    std::set<int> s;
    vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target){
    if (!contains(source))
        add_vertex(source);
    if (!contains(target))
        add_vertex(target);
    int sourceIndex = index(source);
    int targetIndex = index(target);
    vertices[sourceIndex].insert(targetIndex);
    vertices[targetIndex].insert(sourceIndex);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
    return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const {
    return vertices[v];
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    return indexedLabels[vlabel];
}

vector<string> LabeledGraph::find_neighbors(const string &artist) const {
    vector<string> result;
    if (contains(artist)) {
        int artistIndex = indexedLabels.at(artist);
        for (int neighborIndex : neighbors(artistIndex)) {
            result.push_back(label(neighborIndex));
        }
    }
    return result;
}

map<int, int> LabeledGraph::BFS(int v) {
    map<int, int> parent;
    queue<int> q;
    q.push(v);
    parent[v] = -1; // Root node has no parent

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : neighbors(current)) {
            if (parent.find(neighbor) == parent.end()) {
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    return parent;
}
vector<int> LabeledGraph::pathTo(const map<int, int> &parent_map, int target) {
    vector<int> path;
    for (int at = target; at != -1; at = parent_map.at(at)) {
        path.push_back(at);
        cout << "Node: " << at << " (" << label(at) << ")" << endl;
    }
    reverse(path.begin(), path.end());
    return path;
}

ostream& operator<< (ostream &out, const LabeledGraph &g) {
    out << "======================================" << std::endl;
    out << "Graph Summary: " << g.V() << " vertices , " << g.E() << " edges." << std::endl;
    out << "======================================" << std::endl;
    for (int i = 0; i < g.V(); i++) {
        out << g.label(i) << " --> ";
        for (int v : g.neighbors(i)) {
            out << g.label(v) << "  ";
        }
        out << std::endl;
    }
    return out;
}