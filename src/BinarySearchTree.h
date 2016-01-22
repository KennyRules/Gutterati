#pragma once

template <class T>
class BinarySearchTree
{
    private:
        struct TreeNode<T>
        {
            T value;
            TreeNode* left;
            TreeNode* right;
        };

    public:
};