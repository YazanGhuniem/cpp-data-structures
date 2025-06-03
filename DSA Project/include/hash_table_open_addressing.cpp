#ifndef HASH_TABLE_OPEN_ADDRESSING_CPP
#define HASH_TABLE_OPEN_ADDRESSING_CPP

#include "hash_table_open_addressing.h"

template<typename K, typename V>
HashTableOpenAddressing<K, V>::HashTableOpenAddressing(size_t initial_size) 
    : table_size(initial_size), num_elements(0), num_deleted(0) {
    table.resize(table_size);
}

template<typename K, typename V>
void HashTableOpenAddressing<K, V>::insert(const K& key, const V& value) {
    resize_if_needed();
    
    size_t index = find_index(key);
    if (index != table_size) {
        // Key already exists, update value
        table[index].value = value;
        return;
    }
    
    // Find empty or deleted slot
    size_t start_index = hash(key);
    index = start_index;
    
    while (table[index].state == OCCUPIED) {
        index = (index + 1) % table_size;
    }
    
    if (table[index].state == DELETED) {
        num_deleted--;
    }
    
    table[index] = Entry(key, value);
    num_elements++;
}

template<typename K, typename V>
bool HashTableOpenAddressing<K, V>::remove(const K& key) {
    size_t index = find_index(key);
    if (index == table_size) {
        return false;  // not found
    }
    
    table[index].state = DELETED;
    num_elements--;
    num_deleted++;
    
    return true;
}

template<typename K, typename V>
bool HashTableOpenAddressing<K, V>::find(const K& key, V& value) const {
    size_t index = find_index(key);
    if (index == table_size) {
        return false;
    }
    
    value = table[index].value;
    return true;
}

template<typename K, typename V>
V& HashTableOpenAddressing<K, V>::operator[](const K& key) {
    size_t index = find_index(key);
    if (index != table_size) {
        return table[index].value;
    }
    
    // Key not found, insert with default value
    resize_if_needed();
    
    size_t start_index = hash(key);
    index = start_index;
    
    while (table[index].state == OCCUPIED) {
        index = (index + 1) % table_size;
    }
    
    if (table[index].state == DELETED) {
        num_deleted--;
    }
    
    table[index] = Entry(key, V{});
    num_elements++;
    
    return table[index].value;
}

template<typename K, typename V>
void HashTableOpenAddressing<K, V>::resize_if_needed() {
    double current_load = static_cast<double>(num_elements + num_deleted) / table_size;
    if (current_load > MAX_LOAD_FACTOR) {
        rehash(table_size * 2);
    }
}

template<typename K, typename V>
void HashTableOpenAddressing<K, V>::rehash(size_t new_size) {
    auto old_table = std::move(table);
    table_size = new_size;
    table.clear();
    table.resize(table_size);
    
    size_t old_elements = num_elements;
    num_elements = 0;
    num_deleted = 0;
    
    // Reinsert all occupied entries
    for (const auto& entry : old_table) {
        if (entry.state == OCCUPIED) {
            insert(entry.key, entry.value);
        }
    }
}

template<typename K, typename V>
size_t HashTableOpenAddressing<K, V>::size() const {
    return num_elements;
}

template<typename K, typename V>
bool HashTableOpenAddressing<K, V>::empty() const {
    return num_elements == 0;
}

template<typename K, typename V>
double HashTableOpenAddressing<K, V>::load_factor() const {
    return static_cast<double>(num_elements) / table_size;
}

template<typename K, typename V>
void HashTableOpenAddressing<K, V>::clear() {
    table.clear();
    table.resize(table_size);
    num_elements = 0;
    num_deleted = 0;
}

template<typename K, typename V>
void HashTableOpenAddressing<K, V>::print_stats() const {
    std::cout << "Hash Table (Open Addressing) Stats:" << std::endl;
    std::cout << "  Elements: " << num_elements << std::endl;
    std::cout << "  Table Size: " << table_size << std::endl;
    std::cout << "  Load Factor: " << load_factor() << std::endl;
    std::cout << "  Deleted Entries: " << num_deleted << std::endl;
    
    // Calculate clustering
    size_t max_cluster = 0;
    size_t current_cluster = 0;
    for (const auto& entry : table) {
        if (entry.state == OCCUPIED) {
            current_cluster++;
        } else {
            max_cluster = std::max(max_cluster, current_cluster);
            current_cluster = 0;
        }
    }
    max_cluster = std::max(max_cluster, current_cluster);
    
    std::cout << "  Max Cluster Size: " << max_cluster << std::endl;
}

#endif 