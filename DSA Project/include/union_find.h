#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>
#include <iostream>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;  // for union by rank optimization
    int num_components;
    
public:
    UnionFind(int size);
    ~UnionFind() = default;
    
    // Basic operations
    int find(int x);  // find root with path compression
    void union_sets(int x, int y);  // union by rank
    bool connected(int x, int y);
    
    // Utility
    int get_num_components() const { return num_components; }
    void print_components() const;
};

#include "union_find.cpp"

#endif 