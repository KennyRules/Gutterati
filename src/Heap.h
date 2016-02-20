#pragma once

/// Heap is an abstract class that provides default infrastructure
/// for traditional heap data structure implementations.
/// Heap uses an ArrayList instead of a tree structure to store elements,
/// and uses index math to effectively treat the ArrayList like a tree.
#include "ArrayList.h"

template <typename T>
class Heap 
{
    public:
        Heap();
        /// Inserts a element into the Heap.
        virtual void insert(T aValue) = 0; 

        /// Removes and returns the root element from the Heap.
        virtual T pop() = 0;
        size_t getSize() const;
        bool isEmpty() const;

    protected:
        /// Underlying data structure to hold elements, should be indexes as if it were a tree.
        /// For example, children of element at index i are (2 * i + 1) and (2 * i + 2).
        /// The parent of element at index i is ((i - 1) / 2).
        ArrayList<T> m_heap;

};

/// Default Constructor.
/// Does nothing.
template <typename T>
Heap<T>::Heap()
{
    // Do nothing.
}

/// Gets how many elements are currently contained in the Heap.
/// @return Total number of elements currently in the Heap.
template <typename T>
size_t Heap<T>::getSize() const
{
    return m_heap.getSize();
}

/// Whether or not there are elements currently in the Heap.
/// @return true if the Heap has 0 elements, false otherwise.
template <typename T>
bool Heap<T>::isEmpty() const
{
    return m_heap.getSize() == 0;
}