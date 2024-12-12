#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

    Queue();

public:
    ~Queue();

    // Статический метод создания
    static Queue<T>* create();

    // Отключение семантики копирования и перемещения
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;
    Queue(Queue&&) = delete;
    Queue& operator=(Queue&&) = delete;

    void enqueue(const T& value);
    T dequeue();
    T peek() const;

    // Методы
    bool isEmpty() const;
    std::string toString() const;

    // Преегруженные операторы
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Queue<U>& queue);
};

// Реализация методов 
template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), size(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
Queue<T>* Queue<T>::create() {
    return new Queue<T>();
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node* newNode = new Node(value);
    if (rear) {
        rear->next = newNode;
    } else {
        front = newNode;
    }
    rear = newNode;
    ++size;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    Node* temp = front;
    T value = front->data;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
    --size;
    return value;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
std::string Queue<T>::toString() const {
    std::ostringstream oss;
    Node* current = front;
    while (current) {
        oss << current->data << " ";
        current = current->next;
    }
    return oss.str();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
    os << queue.toString();
    return os;
}

#endif // QUEUE_H
