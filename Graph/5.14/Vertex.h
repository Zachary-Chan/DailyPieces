#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include <string>
#include <iostream>
using std::string;
using std::list;

class Vertex {
protected:
    size_t indegree {};
    list<string> adjList {};

    friend void addEdgeUtil(Vertex& vertex, const string& name);

public:
    explicit Vertex(size_t indegree = 0) : indegree {indegree}      {}
};

void addEdgeUtil(Vertex& vertex, const string& name) {
    vertex.adjList.push_back(name);
}

#endif

