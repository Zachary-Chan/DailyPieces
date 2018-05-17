#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include <unordered_map>
#include <string>
#include <queue>
using std::queue;
using std::string;
using std::unordered_map;
using UnMap = unordered_map<string, Vertex>;

class Graph : public Vertex {
private:
    UnMap vertices {};

    void DFSUtil(const string& entry, unordered_map<string, bool> & visited) const {
        std::cout << entry << ' ';
        visited.at(entry) = true;

        for (const auto& x : vertices.at(entry).adjList) {
            if ( !visited.at(x) ) {
                DFSUtil(x, visited);
            }
        }
    }

public:
    explicit Graph(const UnMap& vertices = UnMap {} ) : vertices {vertices}      {}
    explicit Graph(UnMap&& vertices) : vertices {std::move(vertices) }          {}

    void addEdge(const string& name1, const string& name2) {
        vertices.at(name1).addEdge(name2);
    }

    size_t countOfVertices() const { return vertices.size(); }

    void BFS(const string& entry) const {
        queue<string> que;
        unordered_map <string, bool> visited {countOfVertices() };

        for (const auto& x : vertices) {
            visited[x.first] = false;
        }

        que.push(entry);
        visited.at(entry) = true;

        while ( !que.empty() ) {
            for (const auto& x : vertices.at(que.front() ).adjList) {
                if ( !visited[x] ) {
                    que.push(x);
                    visited.at(x) = true;
                }
            }

            std::cout << que.front() << ' ';
            que.pop();
        }
    }

    void DFS(const string& entry) const {
        unordered_map<string, bool> visited {countOfVertices() };

        for (const auto& x : vertices) {
            visited[x.first] = false;
        }

        DFSUtil(entry, visited);
    }
};

#endif

