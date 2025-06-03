#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "queue.h"

template<typename T>
void Queue<T>::enqueue(const T& value) {
    data.push_back(value);
}

template<typename T>
void Queue<T>::dequeue() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    data.pop_front();
}

template<typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data.front();
}

template<typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data.front();
}

template<typename T>
T& Queue<T>::back() {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data.back();
}

template<typename T>
const T& Queue<T>::back() const {
    if (empty()) {
        throw std::runtime_error("Queue is empty");
    }
    return data.back();
}

template<typename T>
bool Queue<T>::empty() const {
    return data.empty();
}

template<typename T>
size_t Queue<T>::size() const {
    return data.size();
}

template<typename T>
void Queue<T>::clear() {
    data.clear();
}

#endif 