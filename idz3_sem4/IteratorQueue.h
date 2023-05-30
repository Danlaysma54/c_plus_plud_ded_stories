#ifndef IDZ3_SEM4_ITERATORQUEUE_H
#define IDZ3_SEM4_ITERATORQUEUE_H

#include "Queue.h"

class IteratorQueue {
private:
    Queue &queue;
    int begin;

public:
   explicit IteratorQueue(Queue &input_queue) : queue(input_queue), begin(0) {}

    void start() {
        begin = queue.GetHead() % (queue.GetBuffWithMaxsize());
    }

    void next() {
        begin++ % (queue.GetBuffWithMaxsize());
    }

    bool finish() {
        return begin % (queue.GetBuffWithMaxsize()) == queue.GetTail() % (queue.GetBuffWithMaxsize());
    }

    int getValue() {
        return queue.GetArray()[begin% (queue.GetBuffWithMaxsize())];
    }
};


#endif //IDZ3_SEM4_ITERATORQUEUE_H
