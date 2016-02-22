#pragma once

#include "LinkedList.h"

/// SinglyLinkedList implements the LinkedList interface and provides data connected by a single link.
template <typename T>
class SinglyLinkedList : public LinkedList<T>
{
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void insert(T aValue);
        void remove(T aValue);
        void clear() noexcept override;

        T getHead() const;
        T getTail() const;
        T find(T aValue) const;

    private:
        struct Node
        {
            T data;
            Node* next;
        };
        Node* m_head = nullptr;
        Node* m_tail = nullptr;
};

/// Default constructor.
/// SinglyLinkedList will be empty with a null head and tail.
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    // Do nothing.
}

/// Destructor.
/// Deletes all elements in the SinglyLinkedList.
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    this->clear();
}

/// Add a new element to the SinglyLinkedList.
/// Element is added to the tail of the list. This operation is guaranteed to take constant time.
/// @param aValue Value to be added into the list.
template <typename T>
void SinglyLinkedList<T>::insert(T aValue)
{
    Node* newNode = new Node{ aValue, nullptr };
    if (m_tail != nullptr) {
        m_tail->next = newNode;
    }
    else {
        m_head = newNode;
    }
    m_tail = newNode;
    m_size++;
}

/// Remove a element from the SinglLinkedList.
/// Element will be deleted.
/// @param aValue Value to be removed from the SinglyLinkedList.
template <typename T>
void SinglyLinkedList<T>::remove(T aValue)
{
    Node* prevNode = nullptr;
    Node* currentNode = m_head;

    while (currentNode != nullptr) {
        if (currentNode->data == aValue) {
            if (prevNode != nullptr) {
                prevNode->next = currentNode->next;
            } 
            else {
                m_head = m_head->next;
            }
            if (m_head == nullptr || m_tail == currentNode) {
                m_tail = nullptr;
            }
            currentNode->next = nullptr;
            delete currentNode;
            m_size--;
            return;
        }
        else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

/// Removes all elements from the list.
/// This operation will delete the elements and set the size to 0.
template <typename T>
void SinglyLinkedList<T>::clear() noexcept
{
    Node* currentNode = m_head;
    while (currentNode != nullptr) {
        Node* nodeToDelete = currentNode;
        currentNode = currentNode->next;
        delete nodeToDelete;
    }
    m_size = 0;
    m_head = m_tail = nullptr;
}

/// Get the element at the head of the list.
/// The front element will always be the oldest element inserted, beneficial
/// for FIFO data structures like the Queue.
/// @return Element at the head5 of the SinglyLinkedList.
template <typename T>
T SinglyLinkedList<T>::getHead() const
{
    return m_head->data;
}

/// Get the element at the tail of the list.
/// The back element will always be the most recently inserted, which is beneficial
/// for LIFO data structures like the Stack.
/// @return Element at the tail of the SinglyLinkedList.
template <typename T>
T SinglyLinkedList<T>::getTail() const
{
    return m_tail->data;
}

/// Finds a element in the SinglyLinkedList.
/// Will return a pointer to the element.
/// @param aValue Value to find in the SinglyLinkedList.
/// @return Const pointer to the element.
template <typename T>
T SinglyLinkedList<T>::find(T aValue) const
{
    Node* currentNode = m_head;
    while (currentNode != nullptr) {
        if (currentNode->data == aValue) {
            return currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return -1;
}