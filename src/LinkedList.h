#pragma once

#include "GutteratiContainer.h"

/// LinkedList is an interface that provides default infrastructure
/// for traditional linked list data structure implementations.
template <typename T>
class LinkedList : public GutteratiContainer
{
    public:
        /// Insert a element into the LinkedList.
        virtual void insert(T aValue) = 0;

        /// Remove a element from the LinkedList.
        virtual void remove(T aValue) = 0;

        /// Get the element at the head of the LinkedList.
        virtual T getHead() const = 0;

        /// Get the element at the tail of the LinkedList.
        virtual T getTail() const = 0;

        /// Find a element in the LinkedList.
        virtual T find(T aValue) const = 0;
};
