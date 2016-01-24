#pragma once

#include "ArrayList.h"

template <typename T>
class Heap {
    protected:
        ArrayList<T> m_heap;

    public:
        Heap();
        virtual void insert(T aValue) = 0;
        virtual T pop() = 0;
        size_t getSize() const;
        bool isEmpty() const;
};

template <typename T>
Heap<T>::Heap()
{

}

template <typename T>
size_t Heap<T>::getSize() const
{
    return m_heap.getSize();
}

template <typename T>
bool Heap<T>::isEmpty() const
{
    return m_heap.getSize() == 0;
}