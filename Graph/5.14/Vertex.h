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

public:
    explicit Vertex(size_t indegree = 0) : indegree {indegree}      {}

    void addEdge(const string& name) {
	adjList.push_back(name);
    }
};

#endif

