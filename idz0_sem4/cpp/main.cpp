#include <iostream>
#include <vector>
#include "../headers/Methods.h"
#include "../headers/Container.h"

using namespace BoxSpace;
using namespace ContainerSpace;

int main() {
    Box box1 = Box(3, 3, 3, 3, 3);
    Box box2 = Box(1, 1000, 1, 1, 1);
    Box box3 = Box(4, 4, 4, 4, 4);
    Box box4 = Box(5, 5, 5, 5, 5);
    Box box5 = Box(5, 5, 5, 500, 5);
    // Box boxes[4] = {box1, box2, box3, box4};
    //  std::cout << PuttingIt(boxes, 4);
    std::vector<Box> boxes = {box1, box2, box3, box4};
    Container container = Container(100, 100, 100, 100, boxes);
    /*   std::cout << box1 << std::endl;
       std::cin >> box1;
       std::cout << box1;
       std::cout << container; */
    /*   std::cout << container<< std:: endl;
       std:: cin >> container;
       std::cout << container<< std:: endl; */
    container.AddLastBox(box5);
    container[3] = box4;
    std::cout << container[3];
}

