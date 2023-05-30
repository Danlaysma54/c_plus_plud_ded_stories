#include "../headers/BinaryTree.h"
#include "../headers/TreeElem.h"
void BinaryTree::insertElem(TreeElem *&root, std::string word)
{
    if (!root)
    {
        root = new TreeElem(word);
        return;
    }
    if (root->info == word)
    {
        root->numb++;
        return;
    }
    if (word.compare(root->info) < 0)
    {
        insertElem(root->left, word);
    }
    if (word.compare(root->info) > 0)
    {
        insertElem(root->right, word);
    }
}
int BinaryTree::findElemRec(const TreeElem *root, std::string word)
{
    if (!root)
    {
        return 0;
    }
    if (word.compare(root->info) < 0)
    {
        return findElemRec(root->left, word);
    }
    if (word.compare(root->info) > 0)
    {
        return findElemRec(root->right, word);
    }
    return root->numb;
}
void del2(TreeElem *&leftSubTree, TreeElem *&root)
{
    if (leftSubTree->right)
    {
        del2(leftSubTree->right, root);
    }
    else
    {
        root->info = leftSubTree->info;
        root = leftSubTree;
        leftSubTree = leftSubTree->left;
    }
}
bool BinaryTree::deleteElem(TreeElem *&root, std::string word)
{
    if (!root)
    {
        return false;
    }
    if (word.compare(root->info) < 0)
    {
        return deleteElem(root->left, word);
    }
    if (word.compare(root->info) > 0)
    {
        return deleteElem(root->right, word);
    }
    if (root->numb == 1)
    {
        TreeElem *nodeToDel = root;
        if (!root->left)
        {
            root = root->right;
        }
        else if (!root->right)
        {
            root = root->left;
        }
        else
        {
            del2(root->left, nodeToDel);
        }
        delete nodeToDel;
    }
    else
    {
        root->numb--;
    }
    return true;
}
int BinaryTree::numbOfWords(const TreeElem *root)
{
    if (!root)
    {
        return 0;
    }
    const int sum = (root->numb) + numbOfWords(root->left) + numbOfWords(root->right);
    return sum;
}
void BinaryTree::PrintAlphabet(const TreeElem *root)
{
    if (!root)
    {
        return;
    }
    PrintAlphabet(root->left);
    std::cout << root->numb << " " << root->info << " ";
    PrintAlphabet(root->right);
}
BinaryTree::BinaryTree(const std::string &word) : root(new TreeElem(word)) {}
BinaryTree::BinaryTree(BinaryTree &&paste)
{
    root = paste.root;
    paste.root = nullptr;
}
void clearElems(TreeElem *root)
{
    if (!root)
        return; // удалять нечего
    clearElems(root->left);
    clearElems(root->right);
    delete root;
}
void clear(TreeElem *&root)
{
    clearElems(root);
    root = nullptr;
}
TreeElem *copyTree(const TreeElem *root)
{
    if (!root)
    {
        return nullptr;
    }
    TreeElem *rootCopy = new TreeElem(root->info);
    try
    {
        rootCopy->left = copyTree(root->left);
        rootCopy->right = copyTree(root->right);
        return rootCopy;
    }
    catch (std::bad_alloc)
    {
        clear(rootCopy);
        throw;
    }
}
BinaryTree::BinaryTree(const BinaryTree &copy)
{
    if (!copy.root)
    {
        root = nullptr;
    }
    this->root = copyTree(copy.root);
}
BinaryTree::~BinaryTree()
{
    clearElems(root);
}
