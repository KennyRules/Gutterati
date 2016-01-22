#pragma once

template <typename T>
class SinglyLinkedList
{
    private:
        struct Node
        {
            T data;
            Node* next;
        };
        Node* m_head;

    public:
        SinglyLinkedList();

        void add(T aValue);
        void remove(T aValue);
        T find(T aValue) const;
        int size() const;
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : m_head(nullptr) { }

template <typename T>
void SinglyLinkedList<T>::add(T aValue)
{
    Node* newNode = new Node{ aValue, nullptr };
    if (m_head == nullptr) {
        m_head = newNode;
    } 
    else {
        Node* currentNode = m_head;
        while (currentNode->next != nullptr)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }
}


template <typename T>
void SinglyLinkedList<T>::remove(T aValue)
{
    Node* prev = nullptr;
    Node* currentNode = m_head;

    while (currentNode != nullptr) {
        if (currentNode->data == aValue) {
            if (prev != nullptr) {
                prev->next = currentNode->next;
            } 
            else {
                m_head = m_head->next;
            }
            currentNode->next = nullptr;
            delete currentNode;
            return;
        }
        else {
            prev = currentNode;
            currentNode = currentNode->next;
        }
    }
}

template <typename T>
T SinglyLinkedList<T>::find(T aValue) const
{
    Node* currentNode = m_head;
    while (currentNode != nullptr) {
        if (currentNode->data == aValue) {
            return aValue;
        }
        currentNode = currentNode->next;
    }
    return -1;
}

template <typename T>
int SinglyLinkedList<T>::size() const
{
    Node* currentNode = m_head;
    int size = 0;
    while (currentNode != nullptr) {
        size++;
        currentNode = currentNode->next;
    }
    return size;
}