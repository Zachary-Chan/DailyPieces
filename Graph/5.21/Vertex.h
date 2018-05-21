#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include <string>

using std::string;
using std::list;

class Vertex {
protected:
    size_t indegree {};
    list<string> adjVertices;

    friend class Graph;

    void addEdge(const string& name) {
        adjVertices.push_back(name);
    }

public:
    explicit Vertex(size_t indegree = 0) : indegree {indegree}      {}
};

#endif

