#ifndef WHY_NOT_TREEELEM_H_
#define WHY_NOT_TREEELEM_H_
struct TreeElem
{
    int info;
    TreeElem *left;
    TreeElem *right;
    TreeElem(int theInfo, TreeElem *theLeft = nullptr, TreeElem *theRight = nullptr) : info(theInfo), left(theLeft), right(theRight) {}
};
#endif //WHY_NOT_TREEELEM_H_