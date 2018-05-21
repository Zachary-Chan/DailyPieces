#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_set>

using std::unordered_set;
using std::queue;
using std::string;
using std::unordered_map;
using UnMap = unordered_map<string, Vertex>;

class Graph : public Vertex {
private:
    UnMap vertices;

public:
    explicit Graph(const UnMap& vertices = UnMap {} ) : vertices {vertices}      {}
    explicit Graph(UnMap&& vertices) : vertices {std::move(vertices) }      {}

    void addEdge(const string& )    {}

    // Variadic template
    template <typename... Ts>
    void addEdge(const string& name1, const string& name2, const Ts&... names) {
        vertices.at(name1).addEdge(name2);
        addEdge(name1, names...);
    }

    size_t countOfVertices() const  { return vertices.size(); }

    void printAllAdjVertices(const string& name) const {
        for (const auto& x_string : vertices.at(name).adjVertices) {
            std::cout << x_string << ' ';
        }
        std::cout << std::endl;
    }

    void topologicalSort() {
        queue<string> que;

        for (const auto& x_pair : vertices) {
            if ( x_pair.second.indegree == 0) {
                que.push(x_pair.first);
            }
        }

        while ( !que.empty() ) {
            for (const auto& x_string : vertices.at(que.front() ).adjVertices) {
                if ( --vertices.at(x_string).indegree == 0 ) {
                    que.push(x_string);
                }
            }

            std::cout << que.front() << ' ';
            que.pop();
        }
    }
};

#endif

