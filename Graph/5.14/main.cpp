#include "Graph.h"
#include <iostream>
#include <unordered_map>
using std::unordered_map;
using std::pair;
using Pair = pair<string, Vertex>;
using UnMap = unordered_map<string, Vertex>;

int main() {
    UnMap vertices {
        Pair { "0", Vertex {2} },
        Pair { "1", Vertex {2} },
        Pair { "2", Vertex {1} },
        Pair { "3", Vertex {1} },
        Pair { "4", Vertex {} },
        Pair { "5", Vertex {} }
    };

    Graph graph {std::move(vertices) };

    std::cout << vertices.size() << std::endl;
    std::cout << graph.countOfVertices() << std::endl;

    graph.addEdge( "2", "3" );

    graph.addEdge( "3", "1" );

    graph.addEdge( "4", "0" );
    graph.addEdge( "4", "1" );

    graph.addEdge( "5", "0" );
    graph.addEdge( "5", "2" );
}

