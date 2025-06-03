#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"

template<typename T>
void Stack<T>::push(const T& value) {
    data.push_front(value);  // push to front for O(1) operation
}

template<typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    data.pop_front();
}

template<typename T>
T& Stack<T>::top() {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return data.front();
}

template<typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return data.front();
}

template<typename T>
bool Stack<T>::empty() const {
    return data.empty();
}

template<typename T>
size_t Stack<T>::size() const {
    return data.size();
}

template<typename T>
void Stack<T>::clear() {
    data.clear();
}

#endif 