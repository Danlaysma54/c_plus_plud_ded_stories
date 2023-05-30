#include <iostream>
#include <cmath>
#include "../headers/TreeElem.h"
#include "../cpp/TreeRelization.cpp"
int main()
{
  int a = 0;
  TreeElem root(-1);
  Tree tree(1);
  std::vector<int> first = {1};
  std::vector<int> second = {1, 0};
  std::vector<int> forth = {1, 0, 1};
  std::vector<int> third = {0};
  tree.Push(3, first);
  tree.Push(4, second);
  Tree tree2(tree);
  tree.Push(8, third);
  tree.Push(9, forth);
  std::vector<int> path = tree.FindElem(&root, 9);
  tree.PrintLeftRight(tree.root);
  std::cout << std::endl;
  tree.PrintLeftRight(tree2.root);
  std::cout << tree.NumbOfEnum(tree.root) << std::endl;
  std::cout << tree.Positive(tree.root) << std::endl;
  std::cout << tree.ArifmeticAverage(tree.root) << std::endl;
  tree.DeleteAllLeafes(tree.root);
  tree.PrintLeftRight(tree.root);
   Tree test(10);
   std::vector<int> test_first = {1};
   std::vector<int> test_second = {1, 0};
   std::vector<int> test_third = {1, 1};
   std::vector<int> test_fourth = {0};
   std::vector<int> test_fifth = {0, 0};
   std::vector<int> test_sixth = {0, 1};
  test.Push(25, test_first);
  test.Push(30, test_second);
  test.Push(40, test_third);
  test.Push(5, test_fourth);
  test.Push(1, test_fifth);
  test.Push(7, test_sixth);
  std::cout << std::endl
            << test.isBinary(test.root);
}