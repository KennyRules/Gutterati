#pragma once

/// Array is a thin wrapper for a fixed-size array of elements.
/// Array provides range checking for indexing operations and a getSize operation.
template <typename T>
class Array 
{
    private:
        T* m_data;
        size_t m_size;

    public:
        explicit Array(size_t aSize);
        Array(const Array<T>& other);
        Array<T>& operator=(const Array<T>& other);
        ~Array();
        T& operator[](size_t aIndex);
        size_t getSize() const;
};

/// Constructs a new Array.
/// @param aSize Total amount of elements the Array can contain.
template <typename T>
Array<T>::Array(size_t aSize) 
{
    if (aSize <= 0) {
        throw std::invalid_argument("Error: Size for Array must be greater than 0");
    }
    m_size = aSize;
    m_data = new T[m_size]();
}

/// Copy constructor to create a new Array from an existing one.
/// @param other Another array from which to construct a new one.
/// Size and elements will copy over.
template <typename T>
Array<T>::Array(const Array<T>& other)
{
    m_size = other.m_size;
    m_data = new T[m_size]();
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

/// Assignment operator to replace the elements of this Array with the elements of other.
/// @param other Another array from which we will copy the elements and size.
/// Original elements of this Array will be deleted.
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other) {
        m_size = other.m_size;
        if (m_data != nullptr) {
            delete[] m_data;
        }
        m_data = new T[m_size]();
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
   
    return *this;
}

/// Destructor.
/// Deletes all elements.
template <typename T>
Array<T>::~Array()
{
    if (m_data != nullptr) {
        delete[] m_data;
    }
}

/// Subscript operator overload.
/// Checks the range of the index queried and throws std::out_of_range if the index is out of bounds.
/// @param aIndex 0-based index of Array element to return. 
/// @return Element contained at index aIndex.
template <typename T>
T& Array<T>::operator[](size_t aIndex)
{
    if (aIndex >= m_size) {
        throw std::out_of_range("Error: Index is out of bounds.");
    }

    return m_data[aIndex];
}

/// Gets total number of elements that can be stored in the Array. 
/// @return Total number of elements that can be stored in the Array. 
template <typename T>
size_t Array<T>::getSize() const
{
    return m_size;
}