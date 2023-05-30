#include <iostream>
#include "IteratorQueue.h"

int main() {
    Queue queue;
    queue.pushback(1);
    queue.pushback(2);
    queue.pushback(3);
    queue.pop();
    queue.pushback(4);
    queue.pop();
    queue.pop();
    queue.pushback(5);
    queue.pushback(6);
    IteratorQueue iteratorQueue(queue);
    iteratorQueue.start();
    while (!iteratorQueue.finish()) {
        printf("%d", iteratorQueue.getValue());
        iteratorQueue.next();
    }
    std::cout << std::endl;
    queue.pop();
    queue.pop();
    queue.pushback(7);
    queue.pushback(8);
    iteratorQueue.start();
    while (!iteratorQueue.finish()) {
        printf("%d", iteratorQueue.getValue());
        iteratorQueue.next();
    }
}
