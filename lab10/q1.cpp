#include <iostream>

using namespace std;

class AVLTree
{
private:
    struct Node
    {
        int taskId;
        Node *left;
        Node *right;

        Node()
        {
            taskId = -1;
            left = nullptr;
            right = nullptr;
        }
    };
    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
            return -1;
        return max(height(node->left), height(node->right)) + 1;
    }

    // Right rotate subtree
    Node *rotateRight(Node *node)
    {
        Node *leftChild = node->left;
        Node *rightChild = leftChild->right;

        leftChild->right = node;
        node->left = rightChild;

        return leftChild;
    }

    // Left rotate subtree
    Node *rotateLeft(Node *node)
    {
        Node *rightChild = node->right;
        Node *leftChild = rightChild->left;

        rightChild->left = node;
        node->right = leftChild;

        return rightChild;
    }

    // Right-Left rotate subtree
    Node *rotateRightLeft(Node *node)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Left-Right rotate subtree
    Node *rotateLeftRight(Node *node)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Insert a new node in tree
    Node *insert(Node *node, int taskId)
    {
        if (node == nullptr)
        {
            node = new Node;
            node->taskId = taskId;
            return node;
        }
        else if (taskId < node->taskId)
            node->left = insert(node->left, taskId);
        else if (taskId > node->taskId)
            node->right = insert(node->right, taskId);
        else
            return node;

        int balanceFactor = height(node->left) - height(node->right);
        if (balanceFactor > 1)
        {
            if (height(node->left->left) - height(node->left->right) >= 0)
                return rotateRight(node);
            else
                return rotateLeftRight(node);
        }
        if (balanceFactor < -1)
        {
            if (height(node->right->right) - height(node->right->left) >= 0)
                return rotateLeft(node);
            else
                return rotateRightLeft(node);
        }

        return node;
    }

    // Find the node with minimum value
    Node *minValueNode(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Delete a node from the tree
    Node *deleteTask(Node *node, int taskId)
    {
        if (node == nullptr)
            return node;

        if (taskId < node->taskId)
            node->left = deleteTask(node->left, taskId);
        else if (taskId > node->taskId)
            node->right = deleteTask(node->right, taskId);
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
                return node;
            }
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                node = temp;
                return node;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                node = temp;
                return node;
            }

            Node *temp = minValueNode(node->right);
            node->taskId = temp->taskId;
            node->right = deleteTask(node->right, temp->taskId);
        }

        int balanceFactor = height(node->left) - height(node->right);
        if (balanceFactor > 1)
        {
            if (height(node->left->left) - height(node->left->right) >= 0)
                return rotateRight(node);
            else
                return rotateLeftRight(node);
        }
        if (balanceFactor < -1)
        {
            if (height(node->right->right) - height(node->right->left) >= 0)
                return rotateLeft(node);
            else
                return rotateRightLeft(node);
        }

        return node;
    }

    // Print the tree in preorder
    void print(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->taskId << " ";
        print(node->left);
        print(node->right);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    // Insert a new task into the tree
    void insert(int taskId)
    {
        root = insert(root, taskId);
    }

    // Delete a task from the tree
    void deleteTask(int taskId)
    {
        root = deleteTask(root, taskId);
    }

    // Print the tasks in the tree in preorder
    void print()
    {
        print(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.print();

    tree.deleteTask(10);
    tree.print();

    return 0;
}