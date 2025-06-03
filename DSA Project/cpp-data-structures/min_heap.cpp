#ifndef MIN_HEAP_CPP
#define MIN_HEAP_CPP

#include "min_heap.h"
#include <algorithm>

template<typename T>
MinHeap<T>::MinHeap(const std::vector<T>& data) : heap(data) {
    // Build heap from bottom up
    if (heap.size() > 1) {
        for (int i = parent(heap.size() - 1); i >= 0; i--) {
            heapify_down(i);
        }
    }
}

template<typename T>
void MinHeap<T>::insert(const T& value) {
    heap.push_back(value);
    heapify_up(heap.size() - 1);
}

template<typename T>
T MinHeap<T>::extract_min() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    
    T min_value = heap[0];
    
    // Move last element to root and heapify down
    heap[0] = heap.back();
    heap.pop_back();
    
    if (!heap.empty()) {
        heapify_down(0);
    }
    
    return min_value;
}

template<typename T>
T MinHeap<T>::peek_min() const {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}

template<typename T>
void MinHeap<T>::heapify_up(size_t index) {
    while (index > 0) {
        size_t parent_index = parent(index);
        if (heap[index] >= heap[parent_index]) {
            break;  // heap property satisfied
        }
        
        std::swap(heap[index], heap[parent_index]);
        index = parent_index;
    }
}

template<typename T>
void MinHeap<T>::heapify_down(size_t index) {
    while (left_child(index) < heap.size()) {
        size_t min_child_index = left_child(index);
        
        // Find the smaller child
        if (right_child(index) < heap.size() && 
            heap[right_child(index)] < heap[left_child(index)]) {
            min_child_index = right_child(index);
        }
        
        if (heap[index] <= heap[min_child_index]) {
            break;  // heap property satisfied
        }
        
        std::swap(heap[index], heap[min_child_index]);
        index = min_child_index;
    }
}

template<typename T>
bool MinHeap<T>::empty() const {
    return heap.empty();
}

template<typename T>
size_t MinHeap<T>::size() const {
    return heap.size();
}

template<typename T>
void MinHeap<T>::clear() {
    heap.clear();
}

template<typename T>
void MinHeap<T>::print() const {
    std::cout << "Heap: ";
    for (const auto& value : heap) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

template<typename T>
std::vector<T> MinHeap<T>::heap_sort() {
    std::vector<T> sorted_result;
    
    // Extract all elements (this will give us sorted order)
    while (!heap.empty()) {
        sorted_result.push_back(extract_min());
    }
    
    return sorted_result;
}

#endif 