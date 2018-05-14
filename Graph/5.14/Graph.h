#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;
using UnMap = unordered_map<string, Vertex>;

class Graph : public Vertex {
private:
    UnMap vertices {};

public:
    explicit Graph(const UnMap& vertices = UnMap {} ) : vertices {vertices}      {}
    explicit Graph(UnMap&& vertices) : vertices {std::move(vertices) }          {}

    void addEdge(const string& name1, const string& name2) {
	vertices.find(name1)->second.addEdge(name2);
    }

    size_t countOfVertices() const { return vertices.size(); }
};

#endif

