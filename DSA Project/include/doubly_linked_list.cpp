#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include "doubly_linked_list.h"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) 
    : head(nullptr), tail(nullptr), list_size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        push_back(current->data);
        current = current->next;
    }
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* new_node = new Node(value);
    
    if (head == nullptr) {  // empty list
        head = tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    list_size++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    
    if (tail == nullptr) {  // empty list
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    list_size++;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (head == nullptr) return;
    
    if (head == tail) {  // only one element
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    list_size--;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (tail == nullptr) return;
    
    if (head == tail) {  // only one element
        delete tail;
        head = tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    list_size--;
}

template<typename T>
bool DoublyLinkedList<T>::remove(const T& value) {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data == value) {
            // handle different cases
            if (current == head && current == tail) {  // only element
                head = tail = nullptr;
            } else if (current == head) {  // first element
                head = current->next;
                head->prev = nullptr;
            } else if (current == tail) {  // last element
                tail = current->prev;
                tail->next = nullptr;
            } else {  // middle element
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            delete current;
            list_size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
T& DoublyLinkedList<T>::front() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template<typename T>
T& DoublyLinkedList<T>::back() {
    if (tail == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
    if (tail == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;
}

template<typename T>
bool DoublyLinkedList<T>::find(const T& value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
size_t DoublyLinkedList<T>::size() const {
    return list_size;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    list_size = 0;
}

template<typename T>
void DoublyLinkedList<T>::print_forward() const {
    Node* current = head;
    std::cout << "Forward: ";
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::print_backward() const {
    Node* current = tail;
    std::cout << "Backward: ";
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "NULL" << std::endl;
}

#endif 