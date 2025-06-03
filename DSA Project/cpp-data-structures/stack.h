#ifndef STACK_H
#define STACK_H

#include "singly_linked_list.h"

template<typename T>
class Stack {
private:
    SinglyLinkedList<T> data;  // using our linked list as underlying storage
    
public:
    Stack() = default;
    ~Stack() = default;
    
    // Stack operations
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    
    // Utility
    bool empty() const;
    size_t size() const;
    void clear();
};

#include "stack.cpp"

#endif 