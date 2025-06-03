#ifndef HASH_TABLE_CHAINING_CPP
#define HASH_TABLE_CHAINING_CPP

#include "hash_table_chaining.h"
#include <iostream>

template<typename K, typename V>
HashTableChaining<K, V>::HashTableChaining(size_t initial_size) 
    : bucket_count(initial_size), num_elements(0) {
    buckets.resize(bucket_count);
}

template<typename K, typename V>
void HashTableChaining<K, V>::insert(const K& key, const V& value) {
    size_t index = hash(key);
    
    // Check if key already exists
    for (auto& pair : buckets[index]) {
        if (pair.key == key) {
            pair.value = value;  // update existing value
            return;
        }
    }
    
    // Add new key-value pair
    buckets[index].emplace_back(key, value);
    num_elements++;
    
    resize_if_needed();
}

template<typename K, typename V>
bool HashTableChaining<K, V>::remove(const K& key) {
    size_t index = hash(key);
    
    auto& chain = buckets[index];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->key == key) {
            chain.erase(it);
            num_elements--;
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
bool HashTableChaining<K, V>::find(const K& key, V& value) const {
    size_t index = hash(key);
    
    for (const auto& pair : buckets[index]) {
        if (pair.key == key) {
            value = pair.value;
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
V& HashTableChaining<K, V>::operator[](const K& key) {
    size_t index = hash(key);
    
    // Look for existing key
    for (auto& pair : buckets[index]) {
        if (pair.key == key) {
            return pair.value;
        }
    }
    
    // Key not found, insert with default value
    buckets[index].emplace_back(key, V{});
    num_elements++;
    resize_if_needed();
    
    return buckets[index].back().value;
}

template<typename K, typename V>
void HashTableChaining<K, V>::resize_if_needed() {
    if (load_factor() > MAX_LOAD_FACTOR) {
        rehash(bucket_count * 2);
    }
}

template<typename K, typename V>
void HashTableChaining<K, V>::rehash(size_t new_bucket_count) {
    auto old_buckets = std::move(buckets);
    bucket_count = new_bucket_count;
    buckets.clear();
    buckets.resize(bucket_count);
    num_elements = 0;
    
    // Reinsert all elements
    for (const auto& chain : old_buckets) {
        for (const auto& pair : chain) {
            insert(pair.key, pair.value);
        }
    }
}

template<typename K, typename V>
size_t HashTableChaining<K, V>::size() const {
    return num_elements;
}

template<typename K, typename V>
bool HashTableChaining<K, V>::empty() const {
    return num_elements == 0;
}

template<typename K, typename V>
double HashTableChaining<K, V>::load_factor() const {
    return static_cast<double>(num_elements) / bucket_count;
}

template<typename K, typename V>
void HashTableChaining<K, V>::clear() {
    for (auto& chain : buckets) {
        chain.clear();
    }
    num_elements = 0;
}

template<typename K, typename V>
void HashTableChaining<K, V>::print_stats() const {
    std::cout << "Hash Table Stats:" << std::endl;
    std::cout << "  Elements: " << num_elements << std::endl;
    std::cout << "  Buckets: " << bucket_count << std::endl;
    std::cout << "  Load Factor: " << load_factor() << std::endl;
    
    // Chain length distribution
    size_t max_chain = 0;
    size_t empty_buckets = 0;
    for (const auto& chain : buckets) {
        if (chain.empty()) {
            empty_buckets++;
        } else {
            max_chain = std::max(max_chain, chain.size());
        }
    }
    std::cout << "  Empty Buckets: " << empty_buckets << std::endl;
    std::cout << "  Max Chain Length: " << max_chain << std::endl;
}

#endif 