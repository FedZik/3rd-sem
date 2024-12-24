#include <gtest/gtest.h>
#include "../domain/Queue.h" // Подключаем наш заголовочный файл

// Тест на создание очереди
TEST(QueueTests, CreateQueue) {
    Queue<int>* queue = Queue<int>::create();
    EXPECT_TRUE(queue->isEmpty()); // Новая очередь должна быть пустой
    delete queue;
}

// Тест на добавление элементов (enqueue)
TEST(QueueTests, Enqueue) {
    Queue<int>* queue = Queue<int>::create();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    EXPECT_EQ(queue->peek(), 1); // Первый элемент должен быть равен 1
    EXPECT_FALSE(queue->isEmpty()); // Очередь не должна быть пустой

    delete queue;
}

// Тест на удаление элементов (dequeue)
TEST(QueueTests, Dequeue) {
    Queue<int>* queue = Queue<int>::create();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    EXPECT_EQ(queue->dequeue(), 1); // Удаляем первый элемент
    EXPECT_EQ(queue->dequeue(), 2); // Удаляем второй элемент
    EXPECT_EQ(queue->dequeue(), 3); // Удаляем третий элемент
    EXPECT_TRUE(queue->isEmpty()); // Очередь должна быть пустой

    delete queue;
}

// Тест на peek (просмотр головного элемента)
TEST(QueueTests, Peek) {
    Queue<int>* queue = Queue<int>::create();
    queue->enqueue(42);
    EXPECT_EQ(queue->peek(), 42); // Первый элемент должен быть 42
    queue->enqueue(55);
    EXPECT_EQ(queue->peek(), 42); // Peek не удаляет элементы

    delete queue;
}

// Тест на проверку пустоты (isEmpty)
TEST(QueueTests, IsEmpty) {
    Queue<int>* queue = Queue<int>::create();
    EXPECT_TRUE(queue->isEmpty()); // Пустая очередь

    queue->enqueue(10);
    EXPECT_FALSE(queue->isEmpty()); // Очередь не пустая

    queue->dequeue();
    EXPECT_TRUE(queue->isEmpty()); // Очередь снова пустая

    delete queue;
}

// Тест на корректность работы toString()
TEST(QueueTests, ToString) {
    Queue<int>* queue = Queue<int>::create();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);

    EXPECT_EQ(queue->toString(), "10 20 30 "); // Ожидаем строку с элементами

    delete queue;
}

// Тест на исключение при dequeue() из пустой очереди
TEST(QueueTests, DequeueEmptyQueue) {
    Queue<int>* queue = Queue<int>::create();
    EXPECT_THROW(queue->dequeue(), std::length_error); // Ожидаем исключение

    delete queue;
}

// Тест на исключение при peek() из пустой очереди
TEST(QueueTests, PeekEmptyQueue) {
    Queue<int>* queue = Queue<int>::create();
    EXPECT_THROW(queue->peek(), std::length_error); // Ожидаем исключение

    delete queue;
}

// Тест на корректную работу с типом std::string
TEST(QueueTests, StringType) {
    Queue<std::string>* queue = Queue<std::string>::create();
    queue->enqueue("Hello");
    queue->enqueue("World");

    EXPECT_EQ(queue->peek(), "Hello");
    EXPECT_EQ(queue->dequeue(), "Hello");
    EXPECT_EQ(queue->dequeue(), "World");
    EXPECT_TRUE(queue->isEmpty());

    delete queue;
}
