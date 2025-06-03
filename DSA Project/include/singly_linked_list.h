#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

template<typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    size_t list_size;  // keeping track of size for O(1) size() calls
    
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    
    // Copy constructor and assignment operator
    SinglyLinkedList(const SinglyLinkedList& other);
    SinglyLinkedList& operator=(const SinglyLinkedList& other);
    
    // Basic operations
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    bool remove(const T& value);  // removes first occurrence
    
    // Access
    T& front();
    const T& front() const;
    bool find(const T& value) const;
    
    // Utility
    bool empty() const;
    size_t size() const;
    void clear();
    void print() const;  // for debugging
    
    // Iterator support (basic)
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };
    
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

#include "singly_linked_list.cpp"  // template implementation

#endif 