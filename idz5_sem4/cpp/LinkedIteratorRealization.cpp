#include "../headers/LinkedIterator.h"
void LinkedIterator::Start()
{
    begin = 0;
    node =linked_hash_table.buff->nextlink;
}
void LinkedIterator::Next()
{
    node = node->nextlink;
}
bool LinkedIterator::IsFinish()
{
    return node ==linked_hash_table.buff;
}
std::string LinkedIterator::GetValue()
{
    return node->data;
}