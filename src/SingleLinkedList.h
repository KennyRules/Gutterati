#pragma once

class SingleLinkedList
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
        SingleLinkedList();

        void add(int aValue);
        void remove(int aValue);
        int find(int aValue) const;
        int size() const;
};

SingleLinkedList::SingleLinkedList() 
{
    m_head = nullptr;
    m_size = 0;
}

void SingleLinkedList::add(int aValue) 
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

void SingleLinkedList::remove(int aValue) 
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

int SingleLinkedList::find(int aValue) const 
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

int SingleLinkedList::size() const 
{
    return m_size;
}