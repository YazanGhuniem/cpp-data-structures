#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;
    Node* tail;  // makes push_back O(1)
    size_t list_size;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    // Copy constructor and assignment
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    
    // Basic operations
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    bool remove(const T& value);
    
    // Access
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    bool find(const T& value) const;
    
    // Utility
    bool empty() const;
    size_t size() const;
    void clear();
    void print_forward() const;
    void print_backward() const;
    
    // Basic iterator (forward only for now)
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        Iterator& operator--() { current = current->prev; return *this; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };
    
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

#include "doubly_linked_list.cpp"

#endif 