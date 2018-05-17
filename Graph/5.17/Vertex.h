#ifndef VERTEX_H
#define VERTEX_H

#include "Graph.h"
#include <list>
#include <string>
#include <iostream>
using std::string;
using std::list;

class Vertex {
protected:
    size_t indegree {};
    list<string> adjList {};
    friend class Graph;

    void addEdge(const string& name) {
        adjList.push_back(name);
    }

public:
    explicit Vertex(size_t indegree = 0) : indegree {indegree}      {}

};

#endif

