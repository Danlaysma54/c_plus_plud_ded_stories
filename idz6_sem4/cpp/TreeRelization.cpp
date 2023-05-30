#include "../headers/Tree.h"
#include <iostream>
void Tree::Push(const int &x, const std::vector<int> &smth)
{
    TreeElem *tmp;
    tmp = root;
    auto it = smth.cbegin();
    for (; it + 1 != smth.cend() && (tmp->left != nullptr || tmp->right != nullptr); it++)
    {
        if (*it == 0)
        {
            tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }
    if (it + 1 != smth.cend())
    {
        std::cout << "здесь могла быть ваша ошибка" << std::endl;
    }
    else
    {
        if (*(it + 1) == *smth.cend())
        {
            if (*it == 0)
            {
                tmp->left = new TreeElem(x);
            }
            else
            {
                tmp->right = new TreeElem(x);
            }
        }
        else
        {
            tmp->info = x;
        }
    }
}
int Tree::NumbOfEnum(const TreeElem *root)
{
    if (!root)
    {
        return 0;
    }
    return (root->info % 2 == 0) + NumbOfEnum(root->left) + NumbOfEnum(root->right);
}
bool Tree::Positive(const TreeElem *root)
{
    if (!root)
    {
        return true;
    }
    return (root->info > 0) && Positive(root->left) && Positive(root->right);
}
int Arifmetic(const TreeElem *root, double &n)
{
    if (!root)
        return 0;

    ++n;
    return root->info + Arifmetic(root->left, n) + Arifmetic(root->right, n);
}
double Tree::ArifmeticAverage(const TreeElem *root)
{
    if (!root)
    {
        return 0;
    }
    double n = 1;
    const double sum = (root->info) + Arifmetic(root->left, n) + Arifmetic(root->right, n);
    return sum / n;
}
bool Tree::DeleteAllLeafes(TreeElem *root)
{
    if (!root)
    {
        return false;
    }
    if (DeleteAllLeafes(root->left))
    {
        root->left = nullptr;
    }
    if (root->left == nullptr && root->right == nullptr)
    {

        delete root;
        return true;
    }
    if (DeleteAllLeafes(root->right))
    {
        root->right = nullptr;
    }
    return false;
}
void Tree::PrintLeftRight(const TreeElem *root)
{
    if (!root)
    {
        return;
    }
    PrintLeftRight(root->left);
    std::cout << root->info << " ";
    PrintLeftRight(root->right);
}
bool GoEveryWhere(const TreeElem *root, const int &x, std::vector<int> &path)
{
    if (!root)
    {
        return false;
    }
    if (x == root->info)
    {
        return true;
    }
    else
    {
        path.push_back(1);
        if (!GoEveryWhere(root->right, x, path))
        {
            path.pop_back();
            path.push_back(0);
            if (!GoEveryWhere(root->left, x, path))
            {
                path.pop_back();
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
}

std::vector<int> Tree::FindElem(const TreeElem *root, const int &x)
{
    std::vector<int> path;
    if (!root)
    {
        return path;
    }
    if (root->info == x)
    {
        return path;
    }
    path.push_back(1);
    if (!GoEveryWhere(root->right, x, path))
    {
        path.clear();
        path.push_back(0);
        GoEveryWhere(root->left, x, path);
    }

    return path;
}
bool Tree::isBinary(const TreeElem *root)
{
    if (!root)
    {
        return true;
    }
    if (root->left != nullptr)
    {
        if (root->left->info < root->info)
        {
            if (isBinary(root->left))
            {
                if (root->right != nullptr)
                {
                    if (root->right->info > root->info)
                    {
                        return isBinary(root->right);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}
void Tree::PrintTree(const TreeElem *root)
{
    if (root)
    {
        std::cout << root->info << " ";
        PrintTree(root->left);
        std::cout << std::endl << root->info;
        PrintTree(root->right);
    }
}
Tree::Tree(const int &x) : root(new TreeElem(x)) {}
Tree::Tree(Tree &&replace)
{
    root = replace.root;
    replace.root = nullptr;
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
Tree::Tree(const Tree &copy)
{
    if (!copy.root)
    {
        root = nullptr;
    }
    this->root = copyTree(copy.root);
}
Tree::~Tree()
{
    clearElems(root);
}