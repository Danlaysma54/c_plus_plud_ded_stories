#include <iostream>
#include "../headers/HashTable.h"
#include "../headers/Iterator.h"
HashTable ::HashTable()
{
    size = 3;
    arr = new list[size];
}
HashTable::HashTable(const int &input_size)
{
    size = input_size;
    arr = new list[size];
}
int HashTable::hash(const int &a)
{
    return a % size;
}
HashTable::HashTable(const HashTable &copy)
{
    size = copy.size;
    arr = new list[size];
    Iterator iterator(copy);
    for (iterator.Start(); !iterator.IsFinish(); iterator.Next())
    {
        PushFront(iterator.GetValue(), iterator.node->key);
    }
}
HashTable::~HashTable()
{
    Iterator iterator(*this);
    list *tmp;
    iterator.Start();
    tmp = iterator.node;
    while (!iterator.IsFinish())
    {
        iterator.Next();
        delete tmp;
        tmp = iterator.node;
    }
}
HashTable::HashTable(HashTable &&paste)
{
    arr = paste.arr;
    size = paste.size;
    paste.arr = nullptr;
    paste.size = 0;
}
HashTable &HashTable::operator=(const HashTable &copy)
{
    Iterator iterator(*this);
    for (iterator.Start(); !iterator.IsFinish(); iterator.Next())
    {
        delete iterator.node;
    }
    size = copy.size;
    arr = new list[size];
    Iterator iterator_2(copy);
    for (iterator_2.Start(); !iterator_2.IsFinish(); iterator_2.Next())
    {
        PushFront(iterator_2.GetValue(), iterator_2.node->key);
    }
    return *this;
}
HashTable &HashTable::operator=(HashTable &&paste)
{
    Iterator iterator(*this);
    for (iterator.Start(); !iterator.IsFinish(); iterator.Next())
    {
        delete iterator.node;
    }
    arr = paste.arr;
    size = paste.size;
    paste.arr = nullptr;
    paste.size = 0;
    return *this;
}
void HashTable::PushFront(const std::string &a, const int &b)
{
    if (arr[hash(b)].next == nullptr)
    {
        arr[hash(b)].next = new list(nullptr, b, a);
    }
    else
    {
        arr[hash(b)].next = new list(arr[hash(b)].next, b, a);
    }
}
void HashTable::Pop(const int &b)
{
    list *tmp = arr[hash(b)].next;
    {
        if (tmp->key == b)
        {
            delete tmp;
            tmp = nullptr;
        }
        else
        {
            while (tmp->next->key != b)
            {
                tmp = tmp->next;
            }
            if (tmp->next == nullptr)
            {
                delete tmp;
            }
            else
            {
                list *del = tmp->next;
                tmp->next = tmp->next->next;
                delete del;
            }
        }
    }
}
std::string HashTable::FindValue(const int &a)
{
    list tmp = arr[hash(a)];
    while (tmp.key != a)
    {
        tmp = *tmp.next;
    }
    return tmp.data;
}
void HashTable::MakeEmpty()
{
    for (int i = 0; i < size; i++)
    {
        list *deleter = arr[i].next;
        while (arr[i].next != nullptr)
        {
            while (deleter != nullptr)
            {
                deleter = deleter->next;
            }
            delete deleter;
        }
    }
}
bool HashTable::IsEmpty()
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].next != nullptr)
            return false;
    }
    return true;
}
