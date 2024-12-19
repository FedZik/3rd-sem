#include "Queue.h"
#include <iostream>

int main() {
    auto* queue = Queue<int>::create();

    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);

    std::cout << "Queue: " << *queue << std::endl;
    std::cout << "Front element: " << queue->peek() << std::endl;

    queue->dequeue();
    std::cout << "Queue after dequeue: " << *queue << std::endl;

    delete queue;
    return 0;
}
