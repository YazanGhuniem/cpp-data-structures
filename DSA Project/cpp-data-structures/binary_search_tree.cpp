#ifndef BINARY_SEARCH_TREE_CPP
#define BINARY_SEARCH_TREE_CPP

#include "binary_search_tree.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr), tree_size(0) {
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    clear();
}

template<typename T>
void BinarySearchTree<T>::insert(const T& value) {
    root = insert_helper(root, value);
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::insert_helper(Node* node, const T& value) {
    if (node == nullptr) {
        tree_size++;
        return new Node(value);
    }
    
    if (value < node->data) {
        node->left = insert_helper(node->left, value);
    } else if (value > node->data) {
        node->right = insert_helper(node->right, value);
    }
    // if value == node->data, we don't insert duplicates
    
    return node;
}

template<typename T>
bool BinarySearchTree<T>::remove(const T& value) {
    size_t old_size = tree_size;
    root = remove_helper(root, value);
    return tree_size < old_size;  // return true if something was actually removed
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::remove_helper(Node* node, const T& value) {
    if (node == nullptr) {
        return nullptr;  // value not found
    }
    
    if (value < node->data) {
        node->left = remove_helper(node->left, value);
    } else if (value > node->data) {
        node->right = remove_helper(node->right, value);
    } else {
        // Found the node to remove
        tree_size--;
        
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            // Node has two children - find inorder successor
            Node* successor = find_min(node->right);
            node->data = successor->data;
            node->right = remove_helper(node->right, successor->data);
            tree_size++;  // compensate for the decrement above
        }
    }
    
    return node;
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::find_min(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename T>
bool BinarySearchTree<T>::find(const T& value) const {
    return find_helper(root, value);
}

template<typename T>
bool BinarySearchTree<T>::find_helper(Node* node, const T& value) const {
    if (node == nullptr) {
        return false;
    }
    
    if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return find_helper(node->left, value);
    } else {
        return find_helper(node->right, value);
    }
}

template<typename T>
void BinarySearchTree<T>::inorder() const {
    std::cout << "Inorder: ";
    inorder_helper(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::inorder_helper(Node* node) const {
    if (node != nullptr) {
        inorder_helper(node->left);
        std::cout << node->data << " ";
        inorder_helper(node->right);
    }
}

template<typename T>
void BinarySearchTree<T>::preorder() const {
    std::cout << "Preorder: ";
    preorder_helper(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::preorder_helper(Node* node) const {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorder_helper(node->left);
        preorder_helper(node->right);
    }
}

template<typename T>
void BinarySearchTree<T>::postorder() const {
    std::cout << "Postorder: ";
    postorder_helper(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::postorder_helper(Node* node) const {
    if (node != nullptr) {
        postorder_helper(node->left);
        postorder_helper(node->right);
        std::cout << node->data << " ";
    }
}

template<typename T>
void BinarySearchTree<T>::level_order() const {
    if (root == nullptr) {
        std::cout << "Level order: (empty)" << std::endl;
        return;
    }
    
    std::cout << "Level order: ";
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        std::cout << current->data << " ";
        
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

template<typename T>
bool BinarySearchTree<T>::empty() const {
    return root == nullptr;
}

template<typename T>
size_t BinarySearchTree<T>::size() const {
    return tree_size;
}

template<typename T>
int BinarySearchTree<T>::height() const {
    return height_helper(root);
}

template<typename T>
int BinarySearchTree<T>::height_helper(Node* node) const {
    if (node == nullptr) {
        return -1;  // height of empty tree is -1
    }
    
    int left_height = height_helper(node->left);
    int right_height = height_helper(node->right);
    
    return 1 + std::max(left_height, right_height);
}

template<typename T>
void BinarySearchTree<T>::clear() {
    clear_helper(root);
    root = nullptr;
    tree_size = 0;
}

template<typename T>
void BinarySearchTree<T>::clear_helper(Node* node) {
    if (node != nullptr) {
        clear_helper(node->left);
        clear_helper(node->right);
        delete node;
    }
}

template<typename T>
T BinarySearchTree<T>::find_min() const {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

template<typename T>
T BinarySearchTree<T>::find_max() const {
    if (root == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

#endif 