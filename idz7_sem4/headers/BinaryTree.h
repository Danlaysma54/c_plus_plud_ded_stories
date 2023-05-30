#ifndef IDZ7_SEM4_BINARYTREE_H_
#define IDZ7_SEM4_BINARYTREE_H_
#include "TreeElem.h"
#include <iostream>
class BinaryTree
{
public:
    TreeElem *root;
    void insertElem(TreeElem *&root, std::string word);
    int findElemRec(const TreeElem *root, std::string word);
    bool deleteElem(TreeElem*&root,std::string word);
    int numbOfWords(const TreeElem *root);
    void PrintAlphabet(const TreeElem *root);
    BinaryTree(const std::string &word);
    BinaryTree(const BinaryTree &copy);
    BinaryTree(BinaryTree &&paste);
    ~BinaryTree();
};
#endif // IDZ7_SEM4_BINARYTREE_H_