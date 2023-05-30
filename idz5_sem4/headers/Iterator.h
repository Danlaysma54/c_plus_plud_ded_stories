#ifndef IDZ5_SEM4_ITERATOR_H
#define IDZ5_SEM4_ITERATOR_H
#include <iostream>
#include "HashTable.h"
class Iterator
{
  const HashTable &hash_table;
    int begin;
    list *node;
    friend class HashTable;

public:
    Iterator(const HashTable &input_hash_table) : hash_table(input_hash_table), begin(0), node(input_hash_table.arr[0].next) {}
    void Start();
    void Next();
    bool IsFinish();
    std::string GetValue();
};
#endif // IDZ5_SEM4_ITERATOR_H