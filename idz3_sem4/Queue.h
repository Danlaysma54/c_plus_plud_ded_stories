#ifndef IDZ3_SEM4_QUEUE_H
#define IDZ3_SEM4_QUEUE_H

#include <iostream>
#include "MyCustomException.h"

class Queue {
private:
    int *arr;
    int MaxSize;
    int head;
    int tail;


public:
    Queue() {
        MaxSize = 3;
        head = 0;
        tail = 0;
        arr = new int[MaxSize];
    }

    Queue(int input_size, int input_buff) {
        MaxSize = input_size;
        arr = new int[MaxSize];
        head = 0;
        tail = 0;
    }

    Queue(const Queue &a) {
        MaxSize = a.MaxSize;
        arr = new int[MaxSize];
        for (int i = 0; i < a.MaxSize; i++) {
            arr[i] = a.arr[i];
        }
        head = a.head;
        tail = a.tail;
    }

    ~Queue() {
        delete[]arr;
    }

    int GetHead() {
        return head;
    }

    int GetTail() {
        return tail;
    }

    int GetBuffWithMaxsize() {
        return MaxSize + 1;
    }

     const int *GetArray() const {
        return arr;
    }

    bool isEmpty() {
        return head % (MaxSize + 1) == tail % (MaxSize + 1);
    };

    bool isFull() {
        return (tail + 1) % (MaxSize + 1) == head;
    }

    void pushback(const int &n) {
        MyCustomException error;
        if (isFull())
            throw std::exception(error);
        arr[tail++ % (MaxSize + 1)] = n;
    }

    int pop() {
        MyCustomException error;
        if (isEmpty()) {
            throw std::exception(error);
        }
        return arr[head++ % (MaxSize + 1)];
    }

    int top() {
        return arr[head % (MaxSize + 1)];
    }

    int size() {
        return (tail - head) % (MaxSize + 1);
    }

    void MakeEmpty() {
        tail = head;
    }

};

#endif //IDZ3_SEM4_QUEUE_H
