#include "LabeledGraph.h"
#include <iostream>
#include "LabeledGraph.cpp"

using namespace std;

int main() {

    LabeledGraph isaiahgraph;
    isaiahgraph.add_edge("Chris Pratt", "Guardians of the Galaxy");
    isaiahgraph.add_edge("Guardians of the Galaxy", "Zoe Saldana");
    isaiahgraph.add_edge("Guardians of the Galaxy", "Vin Diesel");
    isaiahgraph.add_edge("Zoe Saldana", "Avatar");
    isaiahgraph.add_edge("Vin Diesel", "The Fate of the Furious");
    isaiahgraph.add_edge("Avatar", "Sam Worthington");
    isaiahgraph.add_edge("Avatar", "Michelle Rodriguez");
    isaiahgraph.add_edge("The Fate of the Furious", "Michelle Rodriguez");

    cout << isaiahgraph << endl;

    return 0;
}

//The new variables that were added to LabeledGraph that are not in Graph are labeld and indexedLabels. The labeld vector is used to store the labels of the vertices 
// add_vertex and add_edge were modified to include the labels of the vertices. The indexedLabels map is used to store the index of the vertices in the vertices vector