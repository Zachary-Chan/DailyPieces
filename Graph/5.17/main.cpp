#include "Graph.h"
#include <iostream>
#include <unordered_map>
using std::unordered_map;
using std::pair;
using Pair = pair<string, Vertex>;
using UnMap = unordered_map<string, Vertex>;

int main() {
    UnMap vertices {
        { "0", Vertex {1} },
        { "1", Vertex {1} },
        { "2", Vertex {2} },
        { "3", Vertex {2} }
    };

    Graph graph {std::move(vertices) };

    graph.addEdge( "0", "2" );
    graph.addEdge( "0", "1" );

    graph.addEdge( "1", "2" );


    graph.addEdge( "2", "3" );


    graph.BFS( "0" );
    std::cout << std::endl;
    graph.DFS( "0" );
}
