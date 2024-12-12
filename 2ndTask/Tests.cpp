#include "Queue.h"
#include <cassert>
#include <iostream>

void testQueue() {
    auto* queue = Queue<int>::create();

    assert(queue->isEmpty());

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    assert(!queue->isEmpty());
    assert(queue->peek() == 1);

    assert(queue->dequeue() == 1);
    assert(queue->peek() == 2);

    assert(queue->dequeue() == 2);
    assert(queue->dequeue() == 3);

    assert(queue->isEmpty());

    delete queue;

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testQueue();
    return 0;
}
