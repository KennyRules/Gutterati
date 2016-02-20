#pragma once

#include "LinkedList.h"

/// SinglyLinkedList implements the LinkedList interface and provides data connected by a single link.
template <typename T>
class SinglyLinkedList : public LinkedList<T>
{
    public:
        SinglyLinkedList();

        void insert(const T& aValue);
        void remove(const T& aValue);
        const T* find(const T& aValue) const;
        size_t getSize() const;

    private:
        struct Node
        {
            const T& data;
            Node* next;
        };
        Node* m_head = nullptr;
};


/// Default constructor.
/// SinglyLinkedList will be empty with a null head.
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    // Do nothing.
}

/// Add a new element to the SinglyLinkedList.
/// Element is added as the new head of the list, providing fast insertion time.
/// @param aValue Value to be added into the list.
template <typename T>
void SinglyLinkedList<T>::insert(const T& aValue)
{
    Node* newNode = new Node{ aValue, nullptr };
    newNode->next = m_head;
    m_head = newNode;
}

/// Remove a element from the SinglLinkedList.
/// Element will be deleted.
/// @param aValue Value to be removed from the SinglyLinkedList.
template <typename T>
void SinglyLinkedList<T>::remove(const T& aValue)
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
            currentNode->next = nullptr;
            delete currentNode;
            return;
        }
        else {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

/// Finds a element in the SinglyLinkedList.
/// Will return a pointer to the element.
/// @param aValue Value to find in the SinglyLinkedList.
/// @return Const pointer to the element.
template <typename T>
const T* SinglyLinkedList<T>::find(const T& aValue) const
{
    Node* currentNode = m_head;
    while (currentNode != nullptr) {
        if (currentNode->data == aValue) {
            return &currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return nullptr;
}

/// Returns the size of the SinglyLinkedList, which is the total number of 
/// elements currently inserted.
/// @return Current size of the SinglyLinkedList.
template <typename T>
size_t SinglyLinkedList<T>::getSize() const
{
    Node* currentNode = m_head;
    int size = 0;
    while (currentNode != nullptr) {
        size++;
        currentNode = currentNode->next;
    }
    return size;
}