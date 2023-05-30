#ifndef WHY_NOT_TREE_H_
#define WHY_NOT_TREE_H_
#include "TreeElem.h"
#include <iostream>
#include <vector>
class Tree
{
public:
    TreeElem *root;
    void Push(const int &x, const std::vector<int> &smth);
    void PrintLeftRight(const TreeElem *root);
    int NumbOfEnum(const TreeElem *root);
    bool Positive(const TreeElem *root);
    bool DeleteAllLeafes(TreeElem *root);
    double ArifmeticAverage(const TreeElem *root);
    std::vector<int> FindElem(const TreeElem *root, const int &x);
    void PrintTree(const TreeElem *root);
    bool isBinary(const TreeElem *root);
    Tree(const int &x);
    Tree(const Tree &copy);
    Tree(Tree &&replace);
    ~Tree();
};
#endif // WHY_NOT_TREE_H_