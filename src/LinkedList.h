#pragma once

#include <stdexcept>

/// LinkedList is an interface that provides default infrastructure
/// for traditional linked list data structure implementations.
template <typename T>
class LinkedList
{
    public:
        /// Insert a element into the LinkedList.
        virtual void insert(T aValue) = 0;

        /// Remove a element from the LinkedList.
        virtual void remove(T aValue) = 0;

        /// Find a element in the LinkedList.
        virtual T find(T aValue) const = 0;

        /// Get the total number of elements in the LinkedList.
        virtual size_t getSize() const = 0; 
};
