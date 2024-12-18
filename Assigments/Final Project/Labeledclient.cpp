#include "LabeledGraph.h"
#include <iostream>
#include <queue>
#include "LabeledGraph.cpp"


using namespace std;



int main() {

    LabeledGraph isaiahgraph("/workspaces/CS-312/Assigments/Final Project/artists_pairs.txt");

    string source;
    cout << "Enter the name of the source musical artist: ";
    getline(cin, source);

    if (!isaiahgraph.contains(source)) {
        cout << "Source artist not found in the graph." << endl;
        return 1;
    }

    int sourceIndex = isaiahgraph.index(source);
    map<int, int> parent = isaiahgraph.BFS(sourceIndex);
    cout << "All (shortest) paths from " << source << " to other vertices have been created." << endl;

    while (true) {
        string target;
        cout << "Enter the name of the target musical artist (or type '-1' to quit): ";
        getline(cin, target);

        if (target == "-1") {
            cout << "Goodbye." << endl;
            break;
        }

        if (!isaiahgraph.contains(target)) {
            cout << "Target artist not found in the graph." << endl;
            continue;
        }

        int targetIndex = isaiahgraph.index(target);

        if (parent.find(targetIndex) == parent.end()) {
            cout << "No path found from " << source << " to " << target << "." << endl;
        } else {
            vector<int> pathIndices = isaiahgraph.pathTo(parent, targetIndex);
            cout << "Shortest Path from " << source << " to " << target << ":" << endl;
            for (int index : pathIndices) {
                cout << isaiahgraph.label(index);
                if (index != pathIndices.back()) {
                    cout << " --> ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}


//The new variables that were added to LabeledGraph that are not in Graph are labeld and indexedLabels. The labeld vector is used to store the labels of the vertices 
// add_vertex and add_edge were modified to include the labels of the vertices. The indexedLabels map is used to store the index of the vertices in the vertices vector