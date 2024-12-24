#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <memory>

/**
 * @brief Шаблон класса Queue, представляющий очередь с операциями вставки и удаления.
 * @param T Тип данных, который будет храниться в очереди.
 */
template <typename T>
class Queue
{
private:
    /**
     * @brief Структура для очереди.
     */
    struct Node
    {
        T data;
        Node* next;

        /**
         * @brief Конструктор для создания узла с заданным значением.
         * @param value Значение, которое будет храниться в узле.
         */
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* last;
    int size;

public:
    /**
     * @brief Конструктор по умолчанию.
     * Инициализирует пустую очередь.
     */
    Queue();

    /**
     * @brief Деструктор.
     * Освобождает память, занятую всеми элементами очереди.
     */
    ~Queue();

    /**
     * @brief Конструктор копирования.
     * Создает копию переданной очереди.
     * @param other Очередь для копирования.
     */
    Queue(const Queue& other);

    /**
     * @brief Оператор присваивания копированием.
     * Выполняет копирование переданной очереди.
     * @param other Очередь для копирования.
     * @return Ссылка на текущий объект.
     */
    Queue& operator=(const Queue& other);

    /**
     * @brief Конструктор перемещения.
     * Перемещает данные из переданной очереди.
     * @param other Очередь для перемещения.
     */
    Queue(Queue&& other) noexcept;

    /**
     * @brief Оператор присваивания перемещением.
     * Перемещает данные из переданной очереди.
     * @param other Очередь для перемещения.
     * @return Ссылка на текущий объект.
     */
    Queue& operator=(Queue&& other) noexcept;

    /**
     * @brief Создает экземпляр очереди.
     * @return Указатель на новый объект очереди.
     */
    static Queue<T>* create();

    /**
     * @brief Добавляет элемент в конец очереди.
     * @param value Значение для добавления.
     */
    void enqueue(const T& value);

    /**
     * @brief Удаляет и возвращает элемент из начала очереди.
     * @return Значение удаленного элемента.
     * @throw std::length_error Если очередь пуста.
     */
    T dequeue();

    /**
     * @brief Возвращает элемент из начала очереди без удаления.
     * @return Значение элемента из начала очереди.
     * @throw std::length_error Если очередь пуста.
     */
    T peek() const;

    /**
     * @brief Проверяет, пуста ли очередь.
     * @return true, если очередь пуста, иначе false.
     */
    bool isEmpty() const;

    /**
     * @brief Возвращает строковое представление очереди.
     * @return Строка с элементами очереди, разделенными пробелами.
     */
    std::string toString() const;

    /**
     * @brief Перегрузка оператора вывода для очереди.
     * @param os Поток для вывода.
     * @param queue Очередь, которую нужно вывести.
     * @return Ссылка на поток вывода.
     */
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
        throw std::length_error("Queue is empty");
    }
    Node* temp = front;
    auto value = front->data;
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
        throw std::length_error("Queue is empty");
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
