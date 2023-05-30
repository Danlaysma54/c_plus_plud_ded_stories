#ifndef IDZ4_SEM4_ITERATOR_H
#define IDZ4_SEM4_ITERATOR_H
class Iterator
{
public:
    virtual void Start() = 0;
    virtual int GetElem() = 0;
    virtual void Next() = 0;
    virtual bool IsFinish() = 0;
};
#endif // IDZ4_SEM4_ITERATOR_H