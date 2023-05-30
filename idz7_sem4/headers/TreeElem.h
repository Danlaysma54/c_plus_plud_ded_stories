#ifndef IDZ7_SEM4_TREEELEM_H_
#define IDZ7_SEM4_TREEELEM_H_
#include <iostream>
struct TreeElem
{
    std::string info;
    int numb;
    TreeElem *left;
    TreeElem *right;
    TreeElem(std::string theInfo,TreeElem *theLeft = nullptr, TreeElem *theRight = nullptr) : info(theInfo),numb(1), left(theLeft), right(theRight) {}
};
#endif // IDZ7_SEM4_TREEELEM_H_