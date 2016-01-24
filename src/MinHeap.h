#pragma once

#include "Heap.h"

template <typename T>
class MinHeap : public Heap<T> {
    using Heap<T>::m_heap;

    public:
        MinHeap();
        virtual void insert(T aValue) override;
        virtual T pop() override;
        T getMin();
};

template <typename T>
MinHeap<T>::MinHeap()
{
    
}

template <typename T>
void MinHeap<T>::insert(T aValue)
{
    m_heap.insert(aValue);
    int childIndex = m_heap.getSize() - 1;
    int parentIndex = (int)((childIndex - 1) / 2);

    while (parentIndex >= 0 && m_heap[childIndex] < m_heap[parentIndex]) {
        std::swap(m_heap[childIndex], m_heap[parentIndex]);
        childIndex = parentIndex;
        parentIndex = ((childIndex - 1) / 2);
    }
}

template <typename T>
T MinHeap<T>::pop()
{
    T minItem = m_heap[0];
    int heapSize = (int)m_heap.getSize();
    m_heap[0] = m_heap[heapSize - 1];
    m_heap.removeLast();
    heapSize--;

    // Sift the root down, swapping it with the lesser of its left and right children.
    int parentIndex = 0;
    int leftIndex = 1;
    int rightIndex = 2;
    while (parentIndex < heapSize - 1 && rightIndex <= heapSize - 1) {
        size_t minIndex = m_heap[leftIndex] < m_heap[rightIndex] ? leftIndex : rightIndex;
        if (m_heap[parentIndex] > m_heap[minIndex]) {
            std::swap(m_heap[parentIndex], m_heap[minIndex]);
        }
        parentIndex = minIndex;
        leftIndex = parentIndex * 2 + 1;
        rightIndex = parentIndex * 2 + 2;
    }

    // When there is a leaf on the left but not the right.
    if (leftIndex <= heapSize - 1 && rightIndex >= heapSize && m_heap[parentIndex] > m_heap[leftIndex]) {
        std::swap(m_heap[parentIndex], m_heap[leftIndex]);
    }

    return minItem;
}

template <typename T>
T MinHeap<T>::getMin()
{
    return m_heap[0];
}