#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
class Queue {
private:
    /**
     * @brief Вспомогательная структура для представления узлов очереди.
     */
    struct Node {
        T data; // Данные, хранящиеся в узле.
        Node* next; // Указатель на следующий узел.

        /**
         * @brief Конструктор узла.
         * @param value Значение, которое будет храниться в узле.
         */
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front; // Указатель на первый узел очереди.
    Node* rear; // Указатель на последний узел очереди.
    size_t size; // Количество элементов в очереди.

    /**
     * @brief Приватный конструктор по умолчанию.
     */
    Queue();

public:
    /**
     * @brief Создаёт объект очереди.
     * @return Умный указатель на созданный объект очереди.
     */
    static std::shared_ptr<Queue<T>> create();

    /**
     * @brief Деструктор.
     * Освобождает память, занимаемую узлами очереди.
     */
    ~Queue();

    /**
     * @brief Добавляет элемент в конец очереди.
     * @param value Значение, которое будет добавлено в очередь.
     */
    void enqueue(const T& value);

    /**
     * @brief Удаляет элемент из начала очереди.
     * @return Значение удалённого элемента.
     * @throws std::underflow_error Если очередь пуста.
     */
    T dequeue();

    /**
     * @brief Возвращает значение первого элемента очереди без его удаления.
     * @return Значение первого элемента очереди.
     * @throws std::underflow_error Если очередь пуста.
     */
    T peek() const;

    /**
     * @brief Проверяет, пуста ли очередь.
     * @return true, если очередь пуста, иначе false.
     */
    bool isEmpty() const;

    /**
     * @brief Возвращает количество элементов в очереди.
     * @return Количество элементов.
     */
    size_t getSize() const;

    /**
     * @brief Оператор вывода для отображения содержимого очереди.
     * @param os Поток вывода.
     * @param queue Ссылка на очередь.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
        Node* current = queue.front;
        os << "[";
        while (current) {
            os << current->data;
            if (current->next) os << ", ";
            current = current->next;
        }
        os << "]";
        return os;
    }
};