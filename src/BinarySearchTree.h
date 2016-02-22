#pragma once

/// BinarySearchTree implements a standard binary search tree. that 
/// BinarySearchTree does not guarantee the tree will be balanced, but does guarantee the traditional
/// property that for any Node N, its value is greater than its left child and less than its right child.
template <typename T>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(T aValue);
        void remove(T aValue);
        const T* find(T aValue);
        size_t getSize() const;

    private:
        struct TreeNode
        {
            T value;
            TreeNode* left;
            TreeNode* right;
        };
        TreeNode* m_root = nullptr;
        size_t m_size = 0;
        void deleteNode(TreeNode* aNode);
};

/// Default Constructor.
/// Does nothing.
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    // Do nothing.
}

/// Destructor.
/// Deletes all elements stored inside the BinarySearchTree.
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    deleteNode(m_root);
}

/// Helper function to delete a node and its children.
/// Will completely wipe out the subtree rooted at aNode.
/// @param aNode Root of the subtree to delete.
template <typename T>
void BinarySearchTree<T>::deleteNode(TreeNode* aNode)
{
    if (aNode != nullptr) {
        deleteNode(aNode->left);
        deleteNode(aNode->right);
        delete aNode;
    }
}

/// Inserts a new element into the BinarySearchTree.
/// In the worst case, this operation will take O(n) time, where n is the total amount of elements,
/// because BinarySearchTree is not automatically height balanced.
/// @param aValue Element to insert into the BinarySearchTree.
template <typename T>
void BinarySearchTree<T>::insert(T aValue)
{
    TreeNode* newNode = new TreeNode{ aValue, nullptr, nullptr };
    TreeNode* currentNode = m_root;
    
    while (currentNode != nullptr) {
        if (aValue < currentNode->value) {
            if (currentNode->left == nullptr) {
                currentNode->left = newNode;
                break;
            }
            else {
                currentNode = currentNode->left;
            }
        }
        else if (aValue > currentNode->value) {
            if (currentNode->right == nullptr) {
                currentNode->right = newNode;
                break;
            }
            else {
                currentNode = currentNode->right;
            }
        }
        else {
            throw std::range_error("Error: Adding duplicate value to Tree");
        }
    }

    if (m_root == nullptr) {
        m_root = newNode;
    }
    m_size++;
}

/// Removes a element from the BinarySearchTree.
/// In the worst case, this operation will take O(n) time, where n is the total amount of elements,
/// because BinarySearchTree is not automatically height balanced.
/// @param aValue Element to remove from the BinarySearchTree.
template <typename T>
void BinarySearchTree<T>::remove(T aValue)
{
    TreeNode* parentNode = nullptr;
    TreeNode* currentNode = m_root;
    while (currentNode != nullptr) {
        if (currentNode->value == aValue) {
            break;
        }
        parentNode = currentNode;
        if (aValue < currentNode->value) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }

    // Early exist if we didn't find the node, or it's the only element in the tree.
    if (currentNode == nullptr) {
        return;
    }
    
    m_size--;
    if (currentNode == m_root && currentNode->left == nullptr && currentNode->right == nullptr) {
        delete m_root;
        m_root = nullptr;
        return;
    }

    TreeNode* nodeToSwap = nullptr;
    if (currentNode->left != nullptr) {
        nodeToSwap = currentNode->left;
        parentNode = currentNode;
        while (nodeToSwap->right != nullptr) {
            parentNode = nodeToSwap;
            nodeToSwap = nodeToSwap->right;
        }
        std::swap(currentNode->value, nodeToSwap->value);
        if (parentNode == nullptr) {
            m_root = currentNode;
            parentNode = m_root;
        }
        currentNode = nodeToSwap;
    }
    else if (currentNode->right != nullptr) {
        nodeToSwap = currentNode->right;
        parentNode = currentNode;
        while (nodeToSwap->left != nullptr) {
            parentNode = nodeToSwap;
            nodeToSwap = nodeToSwap->left;
        }
        std::swap(currentNode->value, nodeToSwap->value);
        if (parentNode == nullptr) {
            m_root = currentNode;
            parentNode = m_root;
        }
        currentNode = nodeToSwap;
    }

    TreeNode* nodeToDelete = currentNode;
    if (currentNode->left != nullptr || currentNode->right != nullptr) {
        nodeToSwap = currentNode->left != nullptr ? currentNode->left : currentNode->right;
        
        std::swap(currentNode->value, nodeToSwap->value);
        std::swap(currentNode->left, nodeToSwap->left);
        std::swap(currentNode->right, nodeToSwap->right);
        nodeToDelete = nodeToSwap;
    }

    if (parentNode != nullptr && parentNode->left == nodeToDelete) {
        parentNode->left = nullptr;
    }
    else if (parentNode != nullptr && parentNode->right == nodeToDelete) {
        parentNode->right = nullptr;
    }

    delete nodeToDelete;
}

/// Finds an element in the BinarySearchTree.
/// In the worst case, this operation will take O(n) time, where n is the total amount of elements,
/// because BinarySearchTree is not automatically height balanced.
/// @param aValue Element to locate in the BinarySearchTree.
/// @return A const pointer to that element, or nullptr if it cannot be found.
template <typename T>
const T* BinarySearchTree<T>::find(T aValue)
{
    TreeNode* currentNode = m_root;
    while (currentNode != nullptr) {
        if (currentNode->value == aValue) {
            return &currentNode->value;
        }
        else if (aValue < currentNode->value) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }

    return nullptr;
}

/// Gets how many elements are currently contained in the BinarySearchTree.
/// @return Total number of elements currently in the BinarySearchTree.
template <typename T>
size_t BinarySearchTree<T>::getSize() const
{
    return m_size;
}