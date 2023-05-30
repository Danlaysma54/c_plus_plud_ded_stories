#ifndef IDZ5_SEM4_LINKEDITERATOR_H
#define IDZ5_SEM4_LINKEDITERATOR_H
#include <iostream>
#include "LinkedHashTable.h"
class LinkedIterator
{
  const LinkedHashTable &linked_hash_table;
    int begin;
    LinkedList *node;
    friend class LinkedHashTable;

public:
    LinkedIterator(const LinkedHashTable &input_linked_hash_table) : linked_hash_table(input_linked_hash_table), begin(0), node(input_linked_hash_table.arr[0].next) {}
    void Start();
    void Next();
    bool IsFinish();
    std::string GetValue();
};
#endif // IDZ5_SEM4_LINKEDITERATOR_H