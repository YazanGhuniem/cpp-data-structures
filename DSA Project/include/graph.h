#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include <queue>
#include <stack>

// Simple adjacency list representation
class Graph {
private:
    int num_vertices;
    std::vector<std::list<int>> adj_list;  // adjacency list
    bool is_directed;
    
    void dfs_helper(int vertex, std::vector<bool>& visited) const;
    
public:
    Graph(int vertices, bool directed = false);
    ~Graph() = default;
    
    // Basic operations
    void add_edge(int from, int to);
    void remove_edge(int from, int to);
    bool has_edge(int from, int to) const;
    
    // Traversals
    void dfs(int start_vertex) const;
    void bfs(int start_vertex) const;
    
    // Utility
    void print_graph() const;
    int get_num_vertices() const { return num_vertices; }
    std::vector<int> get_neighbors(int vertex) const;
    
    // Some basic graph algorithms
    bool is_connected() const;  // for undirected graphs
    std::vector<int> topological_sort() const;  // for directed acyclic graphs
};

#include "graph.cpp"

#endif 