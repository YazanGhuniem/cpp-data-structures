#ifndef HASH_TABLE_CHAINING_H
#define HASH_TABLE_CHAINING_H

#include <vector>
#include <list>
#include <functional>

template<typename K, typename V>
class HashTableChaining {
private:
    struct KeyValuePair {
        K key;
        V value;
        
        KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
    };
    
    std::vector<std::list<KeyValuePair>> buckets;
    size_t bucket_count;
    size_t num_elements;
    
    // Simple hash function - could be improved
    size_t hash(const K& key) const {
        std::hash<K> hasher;
        return hasher(key) % bucket_count;
    }
    
    // Load factor management
    static constexpr double MAX_LOAD_FACTOR = 0.75;
    void resize_if_needed();
    void rehash(size_t new_bucket_count);
    
public:
    HashTableChaining(size_t initial_size = 16);
    ~HashTableChaining() = default;
    
    // Basic operations
    void insert(const K& key, const V& value);
    bool remove(const K& key);
    bool find(const K& key, V& value) const;  // returns value through reference
    V& operator[](const K& key);  // insert if not found
    
    // Utility
    size_t size() const;
    bool empty() const;
    double load_factor() const;
    void clear();
    void print_stats() const;  // for debugging
};

#include "hash_table_chaining.cpp"

#endif 