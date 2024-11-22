#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        left = right = NULL;
    }
};

class BT
{
private:
    Node *root;

public:
    BT()
    {
        root = NULL;
    }

    ~BT()
    {
        delete root;
    }

    // Insert a node into the tree
    void insert(int data)
    {
        // If the tree is empty, create a new node and set it as the root
        if (root == NULL)
        {
            root = new Node;
            root->data = data;
            root->left = root->right = NULL;
            return;
        }

        // Find the correct position to insert the new node
        Node *current = root;
        while (current != NULL)
        {
            // If the data is less than the current node's data, go to the left subtree
            if (data < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = new Node;
                    current->left->data = data;
                    current->left->left = current->left->right = NULL;
                    return;
                }
                else
                    current = current->left;
            }
            // If the data is greater than the current node's data, go to the right subtree
            else if (data > current->data)
            {
                if (current->right == NULL)
                {
                    current->right = new Node;
                    current->right->data = data;
                    current->right->left = current->right->right = NULL;
                    return;
                }
                else
                    current = current->right;
            }
            else
                return;
        }
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;

        return current;
    }

    // Delete a node from the tree
    Node *deleteNode(Node *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Search for a node in the tree
    Node *search(int key)
    {
        Node *current = root;
        while (current != NULL)
        {
            if (key == current->data)
            {
                return current;
            }
            else if (key < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return NULL;
    }

    // Returns the root of the tree
    Node *getRoot()
    {
        return root;
    }

    // Display the tree in inorder traversal
    void inorder_traversal(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inorder_traversal(node->left);
        cout << node->data << " ";
        inorder_traversal(node->right);
    }

    // Display the tree in preorder traversal
    void preorder_traversal(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }

    // Display the tree in postorder traversal
    void postorder_traversal(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        cout << node->data << " ";
    }

    // Returns the height of the tree
    int Height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int left_height = Height(node->left);
        int right_height = Height(node->right);
        return max(left_height, right_height) + 1;
    }

    // Returns the number of nodes in the tree
    int total_number_of_nodes(Node *node)
    {
        if (node == NULL)
            return 0;

        return total_number_of_nodes(node->left) + total_number_of_nodes(node->right) + 1;
    }

    // Returns the number of leaf nodes in the tree
    int total_number_of_leaf_nodes(Node *node)
    {
        if (node == NULL)
            return 0;

        if (node->left == NULL && node->right == NULL)
            return 1;

        return total_number_of_leaf_nodes(node->left) + total_number_of_leaf_nodes(node->right);
    }
};

int main()
{
    BT tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);

    tree.inorder_traversal(tree.getRoot());
    cout << endl;

    tree.deleteNode(tree.getRoot(), 30);

    tree.inorder_traversal(tree.getRoot());
    cout << endl;
    tree.preorder_traversal(tree.getRoot());
    cout << endl;
    tree.postorder_traversal(tree.getRoot());
    cout << endl;

    return 0;
}