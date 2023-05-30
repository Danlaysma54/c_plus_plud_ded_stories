#include <iostream>
#include "ListRealization.cpp"
int main() {
  ListRealization deque;
  deque.PushBack(4);
  deque.PushFront(3);
  deque.PushBack(5);
  deque.PushFront(2);
  deque.PushFront(1);

  ListRealization deque1(deque);

  std::cout << "Hello, World!" << std::endl;

  for (ListRealization:: IteratorRealization iterator = deque.GetIteratorOnFirstElem(); !iterator.IsFinish();
       iterator.Next()) {
    std::cout << iterator.GetElem() << "\n";
  }

  std::cout << "----------\n";

  for (ListRealization:: IteratorRealization iterator = deque.GetIteratorOnFirstElem(); !iterator.IsFinish();
       iterator.Next()) {
    if (iterator.GetElem() == 4) {
    deque.PopAt(iterator);
    }
    std::cout << iterator.GetElem() << "\n";
    if (iterator.GetElem() == 3) {
      deque.PushAt(iterator, 999);
    }
  }

  std::cout << "----------\n";

 ListRealization:: IteratorRealization iterator999 = deque.Find(999);
  std::cout << iterator999.GetElem() << "\n";

  std::cout << "----------\n";

  deque.PushAt(iterator999, 777);
  for (ListRealization:: IteratorRealization iterator = deque.GetIteratorOnFirstElem(); !iterator.IsFinish();
       iterator.Next()) {
    std::cout << iterator.GetElem() << "\n";
  }

  std::cout << "----------\n";

for (ListRealization:: IteratorRealization iterator = deque.GetIteratorOnFirstElem(); !iterator.IsFinish();
       iterator.Next()) {
    std::cout << iterator.GetElem() << "\n";
  }

  return 0;
} 
