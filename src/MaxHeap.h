#pragma once

#include "Heap.h"

/// MaxHeap implements the Heap data structure where the root of the Heap is the maximum element.
template <typename T>
class MaxHeap : public Heap<T>
{
    using Heap<T>::m_heap;

    public:
        MaxHeap();
        virtual void insert(T aValue) override;
        virtual T pop() override;
        T getMax();
};

/// Default constructor.
/// Does nothing.
template <typename T>
MaxHeap<T>::MaxHeap()
{
    // Do nothing.
}

/// Inserts a new element into the MaxHeap.
/// Elements are inserted at the end of the heap and then sifted up, making the operation
/// take O(log(n)) time, where n is the new total count of elements.
/// @param aValue Element to insert into the MaxHeap.
template <typename T>
void MaxHeap<T>::insert(T aValue)
{
    m_heap.insert(aValue);
    int childIndex = m_heap.getSize() - 1;
    int parentIndex = (int)((childIndex - 1) / 2);

    while (parentIndex >= 0 && m_heap[childIndex] > m_heap[parentIndex]) {
        std::swap(m_heap[childIndex], m_heap[parentIndex]);
        childIndex = parentIndex;
        parentIndex = ((childIndex - 1) / 2);
    }
}

/// Remove and return the maximum element in the MaxHeap.
/// Removal will take at most O(log(n)) time, where n is the total count of elements prior to deletion.
/// @return The element with maximum value in the MaxHeap.
template <typename T>
T MaxHeap<T>::pop()
{
    T MaxItem = m_heap[0];
    int heapSize = (int)m_heap.getSize();
    m_heap[0] = m_heap[heapSize - 1];
    m_heap.removeLast();
    heapSize--;

    // Sift the root down, swapping it with the lesser of its left and right children.
    int parentIndex = 0;
    int leftIndex = 1;
    int rightIndex = 2;
    while (parentIndex < heapSize - 1 && rightIndex <= heapSize - 1) {
        size_t MaxIndex = m_heap[leftIndex] > m_heap[rightIndex] ? leftIndex : rightIndex;
        if (m_heap[parentIndex] < m_heap[MaxIndex]) {
            std::swap(m_heap[parentIndex], m_heap[MaxIndex]);
        }
        parentIndex = MaxIndex;
        leftIndex = parentIndex * 2 + 1;
        rightIndex = parentIndex * 2 + 2;
    }

    // When there is a leaf on the left but not the right.
    if (leftIndex <= heapSize - 1 && rightIndex >= heapSize && m_heap[parentIndex] < m_heap[leftIndex]) {
        std::swap(m_heap[parentIndex], m_heap[leftIndex]);
    }

    return MaxItem;
}

/// Gets the element at the top of the MaxHeap.
/// Operation is guaranteed to be O(1) time due to the maximum element always being the root.
/// @return Element at the top of the MaxHeap.
template <typename T>
T MaxHeap<T>::getMax()
{
    return m_heap[0];
}