#pragma once

#include <stdexcept>

/// Queue implements a basic First-In First-Out data structure.
template <typename T>
class Queue
{
    public:
        Queue();
        T peek() const;
        size_t getSize() const;
        bool isEmpty() const;
        void enqueue(T aValue);
        T dequeue();

    private:
        struct QueueNode
        {
            T data;
            QueueNode* next;
        };

        QueueNode* m_front = nullptr;
        QueueNode* m_back = nullptr;
        size_t m_size = 0;
};

/// Default constructor.
/// Queue will be empty.
template <class T>
Queue<T>::Queue() 
{ 
    // Do nothing.
}

/// Gets the element at the front of the Queue.
/// The element will still be at the front of the Queue.
/// @return The element at the front of the queue.
template <class T>
T Queue<T>::peek() const
{
    if (m_front == nullptr) {
        throw std::range_error("Error: Queue is empty.");
    }

    return m_front->data;
}

/// Returns the size of the Queue, which is the total number of 
/// elements currently inserted.
/// @return Current size of the Queue.
template <class T>
size_t Queue<T>::getSize() const
{
    return m_size;
}

/// Whether or not there are elements currently in the Queue.
/// @return true if the Queue has 0 elements, false otherwise.
template <class T>
bool Queue<T>::isEmpty() const
{
    return m_size == 0;
}

/// Inserts a new element into the Queue.
/// Element will be inserted at the end of the Queue.
/// @param aValue Element to insert into the Queue.
template <class T>
void Queue<T>::enqueue(T aValue)
{
    if (m_front == nullptr) {
        m_front = new QueueNode{ aValue, nullptr };
        m_back = m_front;
    }
    else {
        auto newNode = new QueueNode{ aValue, nullptr };
        m_back->next = newNode;
        m_back = newNode;
    }
    m_size++;
}

/// Remove and get the element at the front of the Queue.
/// If called on an empty Queue, will throw a range_error.
/// @return Element at the front of the Queue.
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