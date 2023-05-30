#include "Iterator.h"
class List
{
public:
    virtual void PopAt(Iterator &smth) = 0;
    virtual void PushAt(Iterator &smth, const int &a) = 0;
    virtual Iterator &Find(const int &a) = 0;
    virtual void MakeEmpty() = 0;
    virtual bool IsEmpty() = 0;
    virtual int NumbOfElem() = 0;
    virtual Iterator& GetIteratorOnFirstElem() = 0;
};