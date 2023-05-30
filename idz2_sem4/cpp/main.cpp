#include <iostream>
#include "../headers/DynamicArrayInt.h"

int main() {
    DynamicArray test;
    DynamicArray test1(3);
    DynamicArray test2(3, 3);
    DynamicArray test3(3, 3, 3);
    DynamicArray test4(test2);
    DynamicArray test5(std::move(test3));
    DynamicArray test6(3, 2);
    DynamicArray test7;
    DynamicArray test8(10,2);
    std::cout << "test1\n" << test1 << "test2\n" << test2 << "test3\n" << test3 << "test4\n" << test4 << "test5" << "\n"
              << test5 << "test3\n" << test3
              << "test5 size: " << test5.GetSize() << " " << "test5 capacity " << test5.capacity() << "\n";
    std::cout << "test 1 the last elem:\n" << test1[2] << "\n";
//    std::cout<< test1[-1];
//    std::cout<< test1[3];
    test1.reSize(1);
    std::cout << "resize test1\n" << test1;
    test5.reSize(5);
    std::cout << "resize test5\n" << test5;
    test5 = test1;
    std::cout << "after test5=test1\n" << test5;
    test5 = test5;
    std::cout << "after test5=test5\n" << test5;
    std::cout << "test5 > test1\n" << (test5 > test1) << "\n";
    std::cout << "test5 >= test1\n" << (test5 >= test1) << "\n";
    std::cout << "test5 == test1\n" << (test5 == test1) << "\n";
    std::cout << "test2 == test6\n" << (test2 == test6) << "\n";
    //   std::cout << "test1 == test6\n" << (test1 == test6) << "\n";
    std::cout << "test2 != test6\n" << (test2 != test6) << "\n";
    std::cout << "test5 >= test1\n" << (test5 <= test1) << "\n";
    std::cout << "test2 > test6\n" << (test2 > test6) << "\n";
    std::cout << "test6 > test2\n" << (test6 > test2) << "\n";
    std::cout << "test6 < test2\n" << (test6 < test2) << "\n";
    std::cout << "test2 < test6\n" << (test2 < test6) << "\n";
    test7 = test5 + test6;
    std::cout << " test7 = test5 + test6\n" << test7;
    std::cin >> test7;
    std::cout << "test7 after cin\n" << test7;
    test8.reSize(12);
    std::cout << "test8\n" << test8;
}
