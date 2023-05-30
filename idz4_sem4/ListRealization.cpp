#include "List.h"
#include "node.h"
#include <cstdio>
#include <cstdlib>
class ListRealization : public List
{
public:
    node *buff;

public:
    class IteratorRealization : public Iterator
    {
    public:
        node *curr;
        ListRealization &list_realization;
        IteratorRealization(ListRealization &list_realization1) : list_realization(list_realization1), curr(list_realization1.buff->next) {}
        void Start() override
        {
            curr = list_realization.buff->next;
        }
        void Next() override
        {
            curr = curr->next;
        }
        bool IsFinish() override
        {
            return list_realization.buff == curr;
        }
        int GetElem() override
        {
            return curr->data;
        }
    };
    ListRealization()
    {
        buff = new node(nullptr, nullptr, -1);
        buff->next = buff;
        buff->prev = buff;
    }
    ListRealization(const ListRealization &a)
    {
        buff = new node(nullptr, nullptr, -1);
        buff->next = buff;
        buff->prev = buff;
        if (a.buff->next != buff)
        {
            node *tmp = a.buff->next;
            while (tmp != a.buff)
            {
                PushBack(tmp->data);
                tmp = tmp->next;
            }
            tmp = nullptr;
        }
    }
    ListRealization(ListRealization &&a)
    {
        buff = new node(nullptr, nullptr, -1);
        buff->next = buff;
        buff->prev = buff;
        if (a.buff->next != nullptr)
        {
            buff->next = a.buff->next;
            buff->prev = a.buff->prev;
            buff->data = a.buff->data;
            a.buff->prev->next = buff;
            buff = nullptr;
            buff->data = 0;
        }
    }
    ~ListRealization()
    {
        do
        {
            PopBack();
        } while (buff->next != buff);
    }
    ListRealization &operator=(const ListRealization &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        if (buff->next != nullptr)
        {
            node *tmp = obj.buff->next;
            while (buff != buff->next)
            {
                PopBack();
            }
            while (tmp != obj.buff)
            {
                PushBack(tmp->data);
                tmp = tmp->next;
            }
            tmp = nullptr;
        }
        return *this;
    }
    ListRealization &operator=(ListRealization &&obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        if (buff->next != buff)
        {
            buff->next = obj.buff->next;
            buff->prev = obj.buff->prev;
            buff->data = obj.buff->data;
            obj.buff->prev->next = buff;
            buff = nullptr;
            buff->data = 0;
        }
        return *this;
    }
    void PushBack(const int &a)
    {
        if (buff->prev == buff)
        {
            node *new_node = new node(buff, buff, a);
            buff->prev = new_node;
            buff->next = new_node;
        }
        else
        {
            node *new_node = new node(buff, buff->prev, a);
            buff->prev->next = new_node;
            buff->prev = new_node;
        }
    }
    void PushFront(const int &a)
    {
        if (buff->prev == buff)
        {
            node *new_node = new node(buff, buff, a);
            buff->prev = new_node;
            buff->next = new_node;
        }
        else
        {
            node *new_node = new node(buff->next, buff, a);
            buff->next->prev = new_node;
            buff->next = new_node;
        }
    }
    void PushAt(Iterator &smth, const int &a)
    {
        IteratorRealization iterator_realization = dynamic_cast<IteratorRealization &>(smth);
        node *new_node = new node(iterator_realization.curr->next, iterator_realization.curr, a);
        iterator_realization.curr->next = new_node;
    }
    void PopAt(Iterator &smth) override
    {
        IteratorRealization realization = dynamic_cast<IteratorRealization &>(smth);
        node *nCurr = realization.curr;
        nCurr->prev->next = nCurr->next;
        nCurr->next->prev = nCurr->prev;
        nCurr = nullptr;
        *realization.curr = *realization.curr->next;
    }
    void PopFront()
    {
        node *tmp = buff->next;
        buff->next = buff->next->next;
        buff->next->prev = buff;
        delete tmp;
    }
    void PopBack()
    {
        node *tmp = buff->prev;
        buff->prev = buff->prev->prev;
        buff->prev->next = buff;
        delete tmp;
    }
    IteratorRealization &Find(const int &a) override
    {
        auto *realization = new IteratorRealization(*this);
        while (!realization->IsFinish() && a != realization->GetElem())
            realization->Next();
        return *realization;
    }
    void MakeEmpty()
    {
        while (buff->next != buff)
        {
            PopFront();
        }
    }
    int NumbOfElem()
    {
        int count = 0;
        node *numb_of_elem = buff->next;
        while (numb_of_elem != buff)
        {
            count++;
            numb_of_elem = numb_of_elem->next;
        }
        return count;
    }

    bool IsEmpty() override
    {
        return buff->next == buff;
    }
    IteratorRealization &GetIteratorOnFirstElem() override
    {
        auto *tmp = new IteratorRealization(*this);
        return *tmp;
    }
};