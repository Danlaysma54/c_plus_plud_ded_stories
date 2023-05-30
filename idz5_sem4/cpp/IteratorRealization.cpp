#include "../headers/Iterator.h"
void Iterator::Start()
{
      begin = 0;
    node = hash_table.arr[begin].next;
    while (node == nullptr)
    {
        begin++;
        node = hash_table.arr[begin].next;
    }
}
void Iterator::Next()
{

    if (node->next == nullptr)
    {
        begin++;
        node = hash_table.arr[begin].next;
    }
    else
    {
        node = node->next;
    }
}
bool Iterator::IsFinish()
{
    list *tmp = node;
    int end = begin;
    for (int i = begin; i < hash_table.size; i++)
    {
        if (tmp != nullptr)
        {
            return false;
        }
        tmp = hash_table.arr[i].next;
    }
    return true;
}
std::string Iterator::GetValue()
{
    return node->data;
}
