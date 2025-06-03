#ifndef SINGLY_LINKED_LIST_CPP
#define SINGLY_LINKED_LIST_CPP

#include "singly_linked_list.h"

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), list_size(0) {
    // nothing else to do here
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();  // clean up all nodes
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr), list_size(0) {
    // copy all elements from other list
    Node* current = other.head;
    while (current != nullptr) {
        push_back(current->data);
        current = current->next;
    }
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList& other) {
    if (this != &other) {  // avoid self-assignment
        clear();  // remove existing elements
        
        // copy from other
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    list_size++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    
    if (head == nullptr) {
        head = new_node;
    } else {
        // traverse to the end
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    list_size++;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
    if (head == nullptr) {
        return;  // nothing to remove
    }
    
    Node* temp = head;
    head = head->next;
    delete temp;
    list_size--;
}

template<typename T>
bool SinglyLinkedList<T>::remove(const T& value) {
    if (head == nullptr) {
        return false;  // list is empty
    }
    
    // check if first element matches
    if (head->data == value) {
        pop_front();
        return true;
    }
    
    // search through the rest
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != nullptr) {  // found it
        Node* to_delete = current->next;
        current->next = current->next->next;
        delete to_delete;
        list_size--;
        return true;
    }
    
    return false;  // not found
}

template<typename T>
T& SinglyLinkedList<T>::front() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template<typename T>
const T& SinglyLinkedList<T>::front() const {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

template<typename T>
bool SinglyLinkedList<T>::find(const T& value) const {
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
bool SinglyLinkedList<T>::empty() const {
    return head == nullptr;
}

template<typename T>
size_t SinglyLinkedList<T>::size() const {
    return list_size;
}

template<typename T>
void SinglyLinkedList<T>::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    list_size = 0;
}

template<typename T>
void SinglyLinkedList<T>::print() const {
    Node* current = head;
    std::cout << "List: ";
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

#endif 