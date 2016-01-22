#pragma once

#include "SinglyLinkedList.h"

template <typename T>
class TailedLinkedList : public SinglyLinkedList<T>
{
    private:
        typedef SinglyLinkedList<T>::Node Node;
        Node* m_tail;

    public:
        TailedLinkedList();

        void add(T aValue);
        void remove(T aValue);
};

template <typename T>
TailedLinkedList<T>::TailedLinkedList() : m_tail(nullptr) { }

template <typename T>
void TailedLinkedList<T>::add(T aValue)
{
    Node* newNode = new Node{ aValue, nullptr };
    if (m_head == nullptr) {
        m_head = newNode;
        m_tail = m_head;
    }
    else {
        m_tail->next = newNode;
        m_tail = newNode;
    }
}

template <typename T>
void TailedLinkedList<T>::remove(T aValue)
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

            if (m_tail == currentNode) {
                m_tail = nullptr;
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