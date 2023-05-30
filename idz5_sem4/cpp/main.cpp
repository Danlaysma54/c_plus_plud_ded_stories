#include <iostream>
#include "../cpp/HashTableRealization.cpp"
#include "../cpp/IteratorRealization.cpp"
#include "../cpp/LinkedHashTableRealization.cpp"
#include "../cpp/LinkedIteratorRealization.cpp"
int main()
{
   HashTable hash_table;
   hash_table.PushFront("Hello", 2);
   hash_table.PushFront("Bye", 1);
   hash_table.PushFront("How", 4);
   hash_table.PushFront("smth", 3);
   HashTable hash_table2(hash_table);
   hash_table.Pop(1);
   std::cout << hash_table.IsEmpty() << std::endl;
   std::cout << hash_table.FindValue(4) << std::endl;
   Iterator iterator(hash_table);
   HashTable hash_table3;
   hash_table3 = hash_table;
   for (iterator.Start(); !iterator.IsFinish(); iterator.Next())
   {
     std::cout << iterator.GetValue() << std::endl;
   }
   std::cout << std::endl;
   Iterator iterator2(hash_table2);
   for (iterator2.Start(); !iterator2.IsFinish(); iterator2.Next())
   {
     std::cout << iterator2.GetValue() << std::endl;
   } 
  LinkedHashTable linked_hash_table;
  linked_hash_table.PushBack("Hello", 2);
  linked_hash_table.PushBack("Bye", 1);
  linked_hash_table.PushBack("How", 4);
  linked_hash_table.PushBack("smth", 3);
  LinkedHashTable linked_hash_table2(linked_hash_table);
  linked_hash_table2.Pop(4);
  LinkedIterator linked_iterator(linked_hash_table);
  LinkedHashTable linked_hash_table3;
  linked_hash_table3 = linked_hash_table;
  for (linked_iterator.Start(); !linked_iterator.IsFinish(); linked_iterator.Next())
  {
    std::cout << linked_iterator.GetValue() << std::endl;
  }
  LinkedIterator linked_iterator2(linked_hash_table2);
  std::cout << std::endl;
  for (linked_iterator2.Start(); !linked_iterator2.IsFinish(); linked_iterator2.Next())
  {
    std::cout << linked_iterator2.GetValue() << std::endl;
  }
}