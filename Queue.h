#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

template <typename T>
class Queue 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* last;
    int size;

public:
    Queue();
    ~Queue();

    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    Queue(Queue&& other) noexcept;

    Queue& operator=(Queue&& other) noexcept;

    static Queue<T>* create();

    void enqueue(const T& value);
    T dequeue();
    T peek() const;

    bool isEmpty() const;
    std::string toString() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Queue<U>& queue);
};

template <typename T>
Queue<T>::Queue() : front(nullptr), last(nullptr), size(0) {}

template <typename T>
Queue<T>::~Queue() 
{
    while (!isEmpty()) 
    {
        dequeue();
    }
}

template <typename T>
Queue<T>::Queue(const Queue& other) : front(nullptr), last(nullptr), size(0) 
{
    Node* current = other.front;
    while (current) 
    {
        enqueue(current->data);
        current = current->next;
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) 
{
    if (this != &other) 
    {

        while (!isEmpty()) 
        {
            dequeue();
        }

        Node* current = other.front;
        while (current) 
        {
            enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept : front(other.front), last(other.last), size(other.size) 
{
    other.front = nullptr;
    other.last = nullptr;
    other.size = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept 
{
    if (this != &other) 
    {

        while (!isEmpty()) 
        {
            dequeue();
        }

        front = other.front;
        last = other.last;
        size = other.size;

        other.front = nullptr;
        other.last = nullptr;
        other.size = 0;
    }
    return *this;
}

template <typename T>
Queue<T>* Queue<T>::create() 
{
    return new Queue<T>();
}

template <typename T>
bool Queue<T>::isEmpty() const 
{
    return size == 0;
}

template <typename T>
void Queue<T>::enqueue(const T& value) 
{
    Node* newNode = new Node(value);
    if (!isEmpty()) 
    {
        last->next = newNode;
    }
    else 
    {
        front = newNode;
    }
    last = newNode;
    ++size;
}

template <typename T>
T Queue<T>::dequeue() 
{
    if (isEmpty()) 
    {
        throw std::underflow_error("Queue is empty");
    }
    Node* temp = front;
    T value = front->data;
    front = front->next;
    if (!front) 
    {
        last = nullptr;
    }
    delete temp;
    --size;
    return value;
}

template <typename T>
T Queue<T>::peek() const
{
    if (isEmpty()) 
    {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
std::string Queue<T>::toString() const
{
    std::ostringstream oss;
    Node* current = front;
    while (current) 
    {
        oss << current->data << " ";
        current = current->next;
    }
    return oss.str();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) 
{
    os << queue.toString();
    return os;
}

#endif // QUEUE_H
