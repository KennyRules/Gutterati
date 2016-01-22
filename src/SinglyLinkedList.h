#pragma once

class SinglyLinkedList
{
    private:
        struct Node
        {
            int data;
            Node* next;
        };

        Node* m_head;
        int m_size;

    public:
        SinglyLinkedList();

        void add(int aValue);
        void remove(int aValue);
        int find(int aValue) const;
        int size() const;
};

SinglyLinkedList::SinglyLinkedList() 
{
    m_head = nullptr;
    m_size = 0;
}

void SinglyLinkedList::add(int aValue) 
{
    Node* newNode = new Node{ aValue, nullptr };
    if (m_head == nullptr) {
        m_head = newNode;
    } 
    else {
        Node* cur = m_head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = newNode;
    }
    m_size++;
}

void SinglyLinkedList::remove(int aValue) 
{
    Node* prev = nullptr;
    Node* cur = m_head;

    while (cur != nullptr) {
        if (cur->data == aValue) {
            if (prev != nullptr) {
                prev->next = cur->next;
            } 
            else {
                m_head = m_head->next;
            }
            cur->next = nullptr;
            delete cur;
            m_size--;
            return;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
}

int SinglyLinkedList::find(int aValue) const 
{
    Node* cur = m_head;
    while (cur != nullptr) {
        if (cur->data == aValue) {
            return aValue;
        }
        cur = cur->next;
    }
    return -1;
}

int SinglyLinkedList::size() const 
{
    return m_size;
}