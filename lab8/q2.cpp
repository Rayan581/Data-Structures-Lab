#include <iostream>
using namespace std;

class Tree
{
private:
    struct Node
    {
        int value;
        int left;
        int right;
    };

    Node *nodes;
    int N;

public:
    Tree(int n)
    {
        nodes = new Node[n];
        N = n;
    }

    ~Tree()
    {
        delete[] nodes;
    }

    // Add a node to the tree
    void addNode(int value, int left, int right, int index)
    {
        nodes[index].value = value;
        nodes[index].left = left;
        nodes[index].right = right;
    }

    // Print the tree in preorder
    void printPreorder(int node)
    {
        if (node == -1)
            return;
        cout << nodes[node].value << " ";
        printPreorder(nodes[node].left);
        printPreorder(nodes[node].right);
    }

    // Print the tree in inorder
    void printInorder(int node)
    {
        if (node == -1)
            return;
        printInorder(nodes[node].left);
        cout << nodes[node].value << " ";
        printInorder(nodes[node].right);
    }

    // Print the tree in postorder
    void printPostorder(int node)
    {
        if (node == -1)
            return;
        printPostorder(nodes[node].left);
        printPostorder(nodes[node].right);
        cout << nodes[node].value << " ";
    }
};

int main()
{
    Tree tree(4);

    tree.addNode(1, 1, 2, 0);
    tree.addNode(2, -1, 3, 1);
    tree.addNode(3, -1, -1, 2);
    tree.addNode(4, -1, -1, 3);

    cout << "Preorder Traversal: ";
    tree.printPreorder(0);
    cout << endl;

    cout << "Inorder Traversal: ";
    tree.printInorder(0);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.printPostorder(0);
    cout << endl;

    return 0;
}
