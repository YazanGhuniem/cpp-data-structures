#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>

template<typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    size_t tree_size;
    
    // Helper functions for recursion
    Node* insert_helper(Node* node, const T& value);
    Node* remove_helper(Node* node, const T& value);
    Node* find_min(Node* node);
    bool find_helper(Node* node, const T& value) const;
    void inorder_helper(Node* node) const;
    void preorder_helper(Node* node) const;
    void postorder_helper(Node* node) const;
    void clear_helper(Node* node);
    int height_helper(Node* node) const;
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    // Copy constructor and assignment - TODO: implement these properly
    BinarySearchTree(const BinarySearchTree& other) = delete;
    BinarySearchTree& operator=(const BinarySearchTree& other) = delete;
    
    // Basic operations
    void insert(const T& value);
    bool remove(const T& value);
    bool find(const T& value) const;
    
    // Traversals
    void inorder() const;    // left, root, right
    void preorder() const;   // root, left, right
    void postorder() const;  // left, right, root
    void level_order() const; // breadth-first
    
    // Utility
    bool empty() const;
    size_t size() const;
    int height() const;
    void clear();
    
    // Some extra functions that might be useful
    T find_min() const;
    T find_max() const;
};

#include "binary_search_tree.cpp"

#endif 