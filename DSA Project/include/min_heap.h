#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <iostream>

template<typename T>
class MinHeap {
private:
    std::vector<T> heap;
    
    // Helper functions for heap operations
    size_t parent(size_t index) const { return (index - 1) / 2; }
    size_t left_child(size_t index) const { return 2 * index + 1; }
    size_t right_child(size_t index) const { return 2 * index + 2; }
    
    void heapify_up(size_t index);
    void heapify_down(size_t index);
    
public:
    MinHeap() = default;
    MinHeap(const std::vector<T>& data);  // build heap from array
    ~MinHeap() = default;
    
    // Basic operations
    void insert(const T& value);
    T extract_min();
    T peek_min() const;
    
    // Utility
    bool empty() const;
    size_t size() const;
    void clear();
    void print() const;  // for debugging
    
    // Heap sort (modifies the heap)
    std::vector<T> heap_sort();
};

#include "min_heap.cpp"

#endif 