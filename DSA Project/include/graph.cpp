#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.h"

Graph::Graph(int vertices, bool directed) : num_vertices(vertices), is_directed(directed) {
    adj_list.resize(num_vertices);
}

void Graph::add_edge(int from, int to) {
    if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices) {
        throw std::out_of_range("Vertex index out of range");
    }
    
    adj_list[from].push_back(to);
    
    if (!is_directed) {
        adj_list[to].push_back(from);
    }
}

void Graph::remove_edge(int from, int to) {
    if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices) {
        return;
    }
    
    adj_list[from].remove(to);
    
    if (!is_directed) {
        adj_list[to].remove(from);
    }
}

bool Graph::has_edge(int from, int to) const {
    if (from < 0 || from >= num_vertices || to < 0 || to >= num_vertices) {
        return false;
    }
    
    for (int neighbor : adj_list[from]) {
        if (neighbor == to) {
            return true;
        }
    }
    return false;
}

void Graph::dfs(int start_vertex) const {
    if (start_vertex < 0 || start_vertex >= num_vertices) {
        std::cout << "Invalid start vertex" << std::endl;
        return;
    }
    
    std::vector<bool> visited(num_vertices, false);
    std::cout << "DFS from vertex " << start_vertex << ": ";
    dfs_helper(start_vertex, visited);
    std::cout << std::endl;
}

void Graph::dfs_helper(int vertex, std::vector<bool>& visited) const {
    visited[vertex] = true;
    std::cout << vertex << " ";
    
    for (int neighbor : adj_list[vertex]) {
        if (!visited[neighbor]) {
            dfs_helper(neighbor, visited);
        }
    }
}

void Graph::bfs(int start_vertex) const {
    if (start_vertex < 0 || start_vertex >= num_vertices) {
        std::cout << "Invalid start vertex" << std::endl;
        return;
    }
    
    std::vector<bool> visited(num_vertices, false);
    std::queue<int> q;
    
    visited[start_vertex] = true;
    q.push(start_vertex);
    
    std::cout << "BFS from vertex " << start_vertex << ": ";
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";
        
        for (int neighbor : adj_list[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::print_graph() const {
    std::cout << "Graph (" << (is_directed ? "directed" : "undirected") << "):" << std::endl;
    for (int i = 0; i < num_vertices; i++) {
        std::cout << "Vertex " << i << ": ";
        for (int neighbor : adj_list[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<int> Graph::get_neighbors(int vertex) const {
    if (vertex < 0 || vertex >= num_vertices) {
        return {};
    }
    
    std::vector<int> neighbors;
    for (int neighbor : adj_list[vertex]) {
        neighbors.push_back(neighbor);
    }
    return neighbors;
}

bool Graph::is_connected() const {
    if (is_directed) {
        std::cout << "Connectivity check not implemented for directed graphs" << std::endl;
        return false;
    }
    
    if (num_vertices == 0) return true;
    
    std::vector<bool> visited(num_vertices, false);
    dfs_helper(0, visited);
    
    // Check if all vertices were visited
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}

std::vector<int> Graph::topological_sort() const {
    if (!is_directed) {
        std::cout << "Topological sort only works on directed graphs" << std::endl;
        return {};
    }
    
    std::vector<int> in_degree(num_vertices, 0);
    
    // Calculate in-degrees
    for (int i = 0; i < num_vertices; i++) {
        for (int neighbor : adj_list[i]) {
            in_degree[neighbor]++;
        }
    }
    
    std::queue<int> q;
    for (int i = 0; i < num_vertices; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    std::vector<int> result;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);
        
        for (int neighbor : adj_list[current]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    if (result.size() != num_vertices) {
        std::cout << "Graph has a cycle - no topological ordering exists" << std::endl;
        return {};
    }
    
    return result;
}

#endif 