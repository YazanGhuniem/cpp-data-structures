#ifndef UNION_FIND_CPP
#define UNION_FIND_CPP

#include "union_find.h"

UnionFind::UnionFind(int size) : num_components(size) {
    parent.resize(size);
    rank.resize(size, 0);
    
    // Initially, each element is its own parent
    for (int i = 0; i < size; i++) {
        parent[i] = i;
    }
}

int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // path compression
    }
    return parent[x];
}

void UnionFind::union_sets(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    
    if (root_x == root_y) {
        return;  // already in same set
    }
    
    // Union by rank
    if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
    } else if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
    } else {
        parent[root_y] = root_x;
        rank[root_x]++;
    }
    
    num_components--;
}

bool UnionFind::connected(int x, int y) {
    return find(x) == find(y);
}

void UnionFind::print_components() const {
    std::cout << "Number of components: " << num_components << std::endl;
    
    // This is a simple way to show components - not the most efficient
    std::cout << "Elements and their roots: ";
    for (int i = 0; i < parent.size(); i++) {
        std::cout << i << "(" << const_cast<UnionFind*>(this)->find(i) << ") ";
    }
    std::cout << std::endl;
}

#endif 