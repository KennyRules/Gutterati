#pragma once

template <typename T>
class Array 
{
    private:
        T* m_data;
        size_t m_size;

    public:
        Array(size_t aSize);
        Array(const Array<T>& other);
        Array<T>& operator=(Array<T> other);
        ~Array();
        T& operator[](size_t aIndex);
        size_t getSize() const;
};

template <typename T>
Array<T>::Array(size_t aSize) 
{
    if (aSize <= 0) {
        throw std::invalid_argument("Error: Size for Array must be greater than 0");
    }
    m_size = aSize;
    m_data = new T[m_size]();
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
    m_size = other.m_size;
    m_data = new T[m_size]();
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> other)
{
    m_size = other.m_size;
    m_data = new T[m_size]();
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (m_data != nullptr) {
        delete[] m_data;
    }
}

template <typename T>
T& Array<T>::operator[](size_t aIndex)
{
    if (aIndex < 0 || aIndex >= m_size)
        throw std::out_of_range("Error: Index is ou of bounds.");

    return m_data[aIndex];
}

template <typename T>
size_t Array<T>::getSize() const
{
    return m_size;
}