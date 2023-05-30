#ifndef IDZ5_SEM4_HASHTABLE_H
#define IDZ5_SEM4_HASHTABLE_H
#include "List.h"
class HashTable
{
    list *arr;
    int size;
    friend class Iterator;

public:
    void PushFront(const std::string &a, const int &b);
    void Pop(const int &b);
    std::string FindValue(const int &a);
    void MakeEmpty();
    bool IsEmpty();
    int hash(const int &a);
    HashTable();
    ~HashTable();
    HashTable(const int &input_size);
    HashTable(const HashTable &copy);
    HashTable(HashTable &&paste);
    HashTable &operator=(const HashTable &copy);
    HashTable &operator=(HashTable &&paste);
};
#endif // IDZ5_SEM4_HASHTABLE_H