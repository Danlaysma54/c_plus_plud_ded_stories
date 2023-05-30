#include <iostream>
#include "./headers/BinaryTree.h"
#include "./headers/TreeElem.h"
#include "./cpp/BinaryTreeRealization.cpp"
int main()
{
    BinaryTree tree("hello");
    tree.insertElem(tree.root, "Gerhard");
    tree.insertElem(tree.root, "Ruslan");
    tree.insertElem(tree.root, "Ruslan");
    tree.insertElem(tree.root, "Maxim");
    tree.insertElem(tree.root, "Maxim");
    tree.insertElem(tree.root, "Maxim");
    tree.insertElem(tree.root, "German");
    tree.insertElem(tree.root, "Dima");
    tree.insertElem(tree.root, "Andrey");
    tree.insertElem(tree.root, "Katia");
    std::cout << tree.numbOfWords(tree.root) << " " << std::endl;
    tree.PrintAlphabet(tree.root);
    tree.deleteElem(*&tree.root, "Dima");
    tree.deleteElem(*&tree.root, "Maxim");
    std::cout << std::endl;
    std::cout << tree.numbOfWords(tree.root) << " " << std::endl;
    tree.PrintAlphabet(tree.root);
}