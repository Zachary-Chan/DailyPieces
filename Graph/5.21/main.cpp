#include "Graph.h"
#include "Vertex.h"
#include <iostream>
#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;
using UnMap = unordered_map<string, Vertex>;

int main() {
    UnMap vertices {
        { "1", Vertex {} },
        { "2", Vertex {1} },
        { "3", Vertex {2} },
        { "4", Vertex {3} },
        { "5", Vertex {1} },
        { "6", Vertex {3} },
        { "7", Vertex {2} }
    };

    Graph graph {std::move(vertices) };

    graph.addEdge( "1", "2", "3", "4" );
    graph.addEdge( "2", "4", "5" );
    graph.addEdge( "3", "6" );
    graph.addEdge( "4", "3", "6", "7" );
    graph.addEdge( "5", "4", "7" );
    graph.addEdge( "7", "6" );

    graph.topologicalSort();
    //graph.printAllAdjVertices( "5" );
    //graph.func();
}
