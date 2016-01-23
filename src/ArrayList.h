#pragma once

#include "Array.h"

template <typename T>
class ArrayList
{
    private:
        T* m_data = nullptr;
        size_t m_capacity = 0;
        size_t m_size = 0;

    public:
        ArrayList(size_t aCapacity);
        T& operator[](size_t aIndex);
        size_t getSize() const;
        size_t getCapacity() const;
        void insert(T aValue);
};

template <typename T>
ArrayList<T>::ArrayList(size_t aSize)
{
    if (aSize <= 0) {
        throw std::invalid_argument("Error: Size for ArrayList must be greater than 0");
    }
    m_size = aSize;
    m_capacity = ceil(m_size * 1.5);
    m_data = new T[m_size]();
}

template <typename T>
T& ArrayList<T>::operator[](size_t aIndex)
{
    if (aIndex < 0 || aIndex >= m_size)
        throw std::out_of_range("Error: Index is ou of bounds.");

    return m_data[aIndex];
}

template <typename T>
size_t ArrayList<T>::getSize() const
{
    return m_size;
}

template <typename T>
size_t ArrayList<T>::getCapacity() const
{
    return m_capacity;
}

template <typename T>
void ArrayList<T>::insert(T aValue)
{
    if (m_size + 1 == m_capacity) {
        m_capacity = ceil(m_capacity * 1.5);
        T* newData = new T[m_capacity]();
        for (size_t i = 0; i < m_size; ++i) {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
    }
    m_data[m_size] = aValue;
    m_size++;
}