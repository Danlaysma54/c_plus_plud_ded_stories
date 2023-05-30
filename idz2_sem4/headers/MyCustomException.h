#ifndef TEST_MYCUSTOMEXCEPTION_H
#define TEST_MYCUSTOMEXCEPTION_H

#include <iostream>

class MyCustomException : public std::exception {
public:
    char *what() {
        return "Arrays are not equals";
    }
};

#endif //TEST_MYCUSTOMEXCEPTION_H