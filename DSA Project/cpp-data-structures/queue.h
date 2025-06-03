#ifndef QUEUE_H
#define QUEUE_H

#include "doubly_linked_list.h"

template<typename T>
class Queue {
private:
    DoublyLinkedList<T> data;  // using doubly linked list for O(1) operations at both ends
    
public:
    Queue() = default;
    ~Queue() = default;
    
    // Queue operations
    void enqueue(const T& value);  // add to back
    void dequeue();                // remove from front
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    
    // Utility
    bool empty() const;
    size_t size() const;
    void clear();
};

#include "queue.cpp"

#endif 