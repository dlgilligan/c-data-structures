
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

typedef size_t (* hash_function)(void *);
typedef size_t (* compare_equal)(void *, void *);

typedef struct Item {
    void * key;
    void * value;
    struct Item * next;
} Item;

typedef struct HashTable {
    size_t size;
    size_t maxCollisons;
    size_t growthFactor;
    Item ** table;
    hash_function hf;
    compare_equal eq;
} HashTable;

HashTable * hashtable_init(size_t, size_t, size_t, hash_function, compare_equal);

void * hashtable_get(HashTable *, void *);

int hashtable_destroy(HashTable *, void *);

int hashtable_resize(HashTable *, size_t);

int hashtable_add(HashTable *, void *, void *);

int hashtable_remove(HashTable *, void *);

#endif