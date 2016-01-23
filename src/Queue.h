#pragma once

#include <stdexcept>

template <typename T>
class Queue
{
    private:
        struct QueueNode
        {
            T data;
            QueueNode* next;
        };

        QueueNode* m_front;
        QueueNode* m_back;
        int m_size;

    public:
        Queue();
        T peek() const;
        int getSize() const;
        bool isEmpty() const;
        void enqueue(T data);
        T dequeue();
};

template <class T>
Queue<T>::Queue() :
    m_front(nullptr), m_back(nullptr), m_size(0) { }

template <class T>
T Queue<T>::peek() const
{
    if (m_front == nullptr) {
        throw std::range_error("Error: Queue is empty.");
    }

    return m_front->data;
}

template <class T>
int Queue<T>::getSize() const
{
    return m_size;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return m_size == 0;
}

template <class T>
void Queue<T>::enqueue(T data)
{
    if (m_front == nullptr) {
        m_front = new QueueNode{ data, nullptr };
        m_back = m_front;
    }
    else {
        auto newNode = new QueueNode{ data, nullptr };
        m_back->next = newNode;
        m_back = newNode;
    }
    m_size++;
}

template <class T>
T Queue<T>::dequeue()
{
    if (m_front == nullptr) {
        throw std::range_error("Error: Queue is empty.");
    }

    T returnValue = m_front->data;

    if (m_front == m_back) {
        delete m_front;
        m_front = nullptr;
        m_back = nullptr;
    }
    else {
        auto nodeToDelete = m_front;
        m_front = m_front->next;
        delete nodeToDelete;
    }

    m_size--;
    return returnValue;
}