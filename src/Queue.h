#pragma once

#include "SinglyLinkedList.h"

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
        SinglyLinkedList<T> m_data;
        struct QueueNode
        {
            T data;
            QueueNode* next;
        };

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
    if (m_data.isEmpty()) {
        throw std::range_error("Error: Queue is empty.");
    }

    return m_data.getHead();
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
    m_data.insert(aValue);
    m_size++;
}

/// Remove and get the element at the front of the Queue.
/// If called on an empty Queue, will throw a range_error.
/// @return Element at the front of the Queue.
template <class T>
T Queue<T>::dequeue()
{
    if (m_data.isEmpty()) {
        throw std::range_error("Error: Queue is empty.");
    }

    T returnValue = m_data.getHead();
    m_data.remove(returnValue);
    m_size--;
    return returnValue;
}