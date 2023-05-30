#include "../headers/LinkedHashTable.h"
#include "../headers/LinkedIterator.h"
LinkedHashTable ::LinkedHashTable()
{
    size = 3;
    arr = new LinkedList[size];
    buff = new LinkedList(nullptr, nullptr, nullptr, -1, " ");
    buff->nextlink = buff;
    buff->prevlink = buff;
}
LinkedHashTable::LinkedHashTable(const int &input_size)
{
    size = input_size;
    arr = new LinkedList[size];
    buff = new LinkedList(nullptr, nullptr, nullptr, -1, " ");
    buff->nextlink = buff;
    buff->prevlink = buff;
}
int LinkedHashTable::hash(const int &a)
{
    return a % size;
}
LinkedHashTable::LinkedHashTable(const LinkedHashTable &copy)
{
    size = copy.size;
    arr = new LinkedList[size];
     buff = new LinkedList(nullptr, nullptr, nullptr, -1, " ");
    buff->nextlink = buff;
    buff->prevlink = buff;
    LinkedIterator LinkedIterator(copy);
    for (LinkedIterator.Start(); !LinkedIterator.IsFinish(); LinkedIterator.Next())
    {
        PushBack(LinkedIterator.GetValue(), LinkedIterator.node->key);
    }
}
LinkedHashTable::~LinkedHashTable()
{
    LinkedIterator LinkedIterator(*this);
    LinkedList *tmp;
    LinkedIterator.Start();
    tmp = LinkedIterator.node;
    while (!LinkedIterator.IsFinish())
    {
        LinkedIterator.Next();
        delete tmp;
        tmp = LinkedIterator.node;
    }
}
LinkedHashTable::LinkedHashTable(LinkedHashTable &&paste)
{
    arr = paste.arr;
    size = paste.size;
    paste.arr = nullptr;
    paste.size = 0;
}
LinkedHashTable &LinkedHashTable::operator=(const LinkedHashTable &copy)
{
    LinkedIterator linked_iterator(*this);
    for (linked_iterator.Start(); !linked_iterator.IsFinish(); linked_iterator.Next())
    {
        delete linked_iterator.node;
    }
    size = copy.size;
    arr = new LinkedList[size];
    LinkedIterator LinkedIterator_2(copy);
    for (LinkedIterator_2.Start(); !LinkedIterator_2.IsFinish(); LinkedIterator_2.Next())
    {
        PushBack(LinkedIterator_2.GetValue(), LinkedIterator_2.node->key);
    }
    return *this;
}
LinkedHashTable &LinkedHashTable::operator=(LinkedHashTable &&paste)
{
    LinkedIterator LinkedIterator(*this);
    for (LinkedIterator.Start(); !LinkedIterator.IsFinish(); LinkedIterator.Next())
    {
        delete LinkedIterator.node;
    }
    arr = paste.arr;
    size = paste.size;
    paste.arr = nullptr;
    paste.size = 0;
    return *this;
}
void LinkedHashTable::PushBack(const std::string &a, const int &b)
{
    if (buff->nextlink == buff)
    {
        arr[hash(b)].next = new LinkedList(nullptr, buff, buff, b, a);
        buff->nextlink = arr[hash(b)].next;
        buff->prevlink = arr[hash(b)].next;
    }
    else
    {
        if (arr[hash(b)].next == nullptr)
        {
            arr[hash(b)].next = new LinkedList(nullptr, buff, buff->prevlink, b, a);
        }
        else
        {
            arr[hash(b)].next = new LinkedList(arr[hash(b)].next, buff, buff->prevlink, b, a);
        }
        buff->prevlink->nextlink = arr[hash(b)].next;
        buff->prevlink = arr[hash(b)].next;
    }
}
void LinkedHashTable::Pop(const int &b)
{
    LinkedList *tmp = arr[hash(b)].next;
    {
        if (tmp->key == b)
        {
            tmp->prevlink->nextlink = tmp->nextlink;
            tmp->next->prevlink = tmp->prevlink;
            delete tmp;
        }
        else
        {
            while (tmp->next->key != b)
            {
                tmp = tmp->next;
            }
            if (tmp->next == nullptr)
            {
                tmp->prevlink->nextlink = tmp->nextlink;
                tmp->next->prevlink = tmp->prevlink;
                delete tmp;
            }
            else
            {
                tmp->prevlink->nextlink = tmp->nextlink;
                tmp->next->prevlink = tmp->prevlink;
                LinkedList *del = tmp->next;
                tmp->next = tmp->next->next;
                delete del;
            }
        }
    }
}
std::string LinkedHashTable::FindValue(const int &a)
{
    LinkedList tmp = arr[hash(a)];
    while (tmp.key != a)
    {
        tmp = *tmp.next;
    }
    return tmp.data;
}
void LinkedHashTable::MakeEmpty()
{
    for (int i = 0; i < size; i++)
    {
        LinkedList *deleter = arr[i].next;
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
bool LinkedHashTable::IsEmpty()
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].next != nullptr)
            return false;
    }
    return true;
}
