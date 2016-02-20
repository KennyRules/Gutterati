#pragma once

#include "Array.h"

/// ArrayList is a automatically resizing Array supporting insertion and deletion.
/// The total capacity of the ArrayList will always grow at a rate of 1.5.
template <typename T>
class ArrayList
{
    private:
        T* m_data = nullptr;
        size_t m_capacity = 0;
        size_t m_size = 0;

    public:
        ArrayList();
        explicit ArrayList(size_t aSize);
        ArrayList(const ArrayList<T>& other);
        ArrayList<T>& operator=(const ArrayList<T>& other);
        ~ArrayList();
        T& operator[](size_t aIndex);
        const T& operator[](size_t aIndex) const;
        size_t getSize() const;
        size_t getCapacity() const;
        void insert(T aValue);
        void removeLast();
};

/// Default constructor.
/// Size and capacity will be set to 0.
template <typename T>
ArrayList<T>::ArrayList() { }

/// Constructs a new ArrayList with a given initial size.
/// Initializes a new ArrayList able to hold aSize elements.
/// @param aSize Amount of elements the new ArrayList can initially hold without resizing.
/// Must be greater than 0.
template <typename T>
ArrayList<T>::ArrayList(size_t aSize)
{
    if (aSize == 0) {
        throw std::invalid_argument("Error: Size for ArrayList must be greater than 0");
    }
    m_size = aSize;
    m_capacity = (size_t)ceil((double)m_size * 1.5);
    m_data = new T[m_capacity]();
}

/// Copy constructor to create a new ArrayList from an existing one.
/// Size, capacity and elements will be the same.
/// @param other Another ArrayList.
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new T[m_capacity]();
    for (size_t i = 0; i < m_capacity; ++i) {
        m_data[i] = other.m_data[i];
    }
}

/// Assignment operator to replace the elements of this ArrayList with another's.
/// @param other Another ArrayList.
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
{
    if (this != &other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity]();
        for (size_t i = 0; i < m_capacity; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

/// Destructor.
/// Deletes all elements.
template <typename T>
ArrayList<T>::~ArrayList() {
    if (m_data != nullptr) {
        delete[] m_data;
    }
}

/// Subscript operator overload to return non-const reference.
/// Checks the range of the index queried and throws std::out_of_range if the index is out of bounds.
///
/// @param aIndex 0-based index of ArrayList element to return. 
/// @return Non-const reference to Element contained at index aIndex.
template <typename T>
T& ArrayList<T>::operator[](size_t aIndex)
{
    if (aIndex >= m_size)
        throw std::out_of_range("Error: Index is out of bounds.");

    return m_data[aIndex];
}

/// Subscript operator overload to return const reference.
/// Checks the range of the index queried and throws std::out_of_range if the index is out of bounds.
///
/// @param aIndex 0-based index of ArrayList element to return. 
/// @return Const reference to Element contained at index aIndex.
template <typename T>
const T& ArrayList<T>::operator[](size_t aIndex) const
{
    if (aIndex >= m_size)
        throw std::out_of_range("Error: Index is out of bounds.");

    return m_data[aIndex];
}

/// Returns the size of the ArrayList, which is the total number of 
/// elements currently inserted.
/// @return Current size of the ArrayList. BLA
template <typename T>
size_t ArrayList<T>::getSize() const
{
    return m_size;
}

/// Returns the capacity of the ArrayList, which is the total number of
/// elements that can be inserted before a resize operation occurs.
/// @return Current capacity of the ArrayList.
template <typename T>
size_t ArrayList<T>::getCapacity() const
{
    return m_capacity;
}

/// Inserts a new element into the ArrayList.
/// If the new element fills up the capacity, a resizing operation will occur.
/// @param aValue A new element to add.
template <typename T>
void ArrayList<T>::insert(T aValue)
{
    if (m_size + 1 == m_capacity) {
        m_capacity = (size_t)ceil((double)m_capacity * 1.5);
        T* newData = new T[m_capacity]();
        for (size_t i = 0; i < m_size; ++i) {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
    }
    else if (m_size == 0) {
        m_capacity = 2;
        m_data = new T[m_capacity]();
    }
    m_data[m_size] = aValue;
    m_size++;
}

/// Shrinks the ArrayList down one element.
template <typename T>
void ArrayList<T>::removeLast()
{
    if (m_size == 0) {
        throw std::out_of_range("Error: Cannot remove from empty ArrayList");
    }
    m_size--;
}