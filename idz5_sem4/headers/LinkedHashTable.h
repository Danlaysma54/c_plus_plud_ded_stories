#ifndef IDZ5_SEM4_LINKEDHASHTABLE_H
#define IDZ5_SEM4_LINKEDHASHTABLE_H
#include<iostream>
#include "LinkedList.h"
class LinkedHashTable
{
    LinkedList *arr;
    LinkedList *buff;
    int size;
    friend class LinkedIterator;

public:
    void PushBack(const std::string &a, const int &b);
    void Pop(const int &b);
    std::string FindValue(const int &a);
    void MakeEmpty();
    bool IsEmpty();
    int hash(const int &a);
    LinkedHashTable();
    ~LinkedHashTable();
    LinkedHashTable(const int &input_size);
    LinkedHashTable(const LinkedHashTable &copy);
    LinkedHashTable(LinkedHashTable &&paste);
    LinkedHashTable &operator=(const LinkedHashTable &copy);
    LinkedHashTable &operator=(LinkedHashTable &&paste);
};
#endif // IDZ5_SEM4_LINKEDHASHTABLE_H