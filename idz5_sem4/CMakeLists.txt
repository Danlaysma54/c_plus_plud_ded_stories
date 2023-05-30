cmake_minimum_required(VERSION 3.24)
project(idz5_sem4)

set(CMAKE_CXX_STANDARD 17)

add_executable(idz5_sem4 ../headers/HashTable.h ../headers/Iterator.h ../headers/LinkedHashTable.h ../headers/LinkedIterator.h ../headers/List.h ../cpp/HashTableRealization.cpp ../cpp/IteratorRealization.cpp ../cpp/LinkedHashTableRealization.cpp ../cpp/LinkedIteratorRealization.cpp)