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
    int root;
    int N;

public:
    Tree(int n)
    {
        nodes = new Node[n];
        N = n;
        root = -1;
    }

    int getRoot()
    {
        return root;
    }

    void addNode(int value, int left, int right, int index)
    {
        nodes[index].value = value;
        nodes[index].left = left;
        nodes[index].right = right;
    }

    // Print the tree in BFS (level-order) traversal
    void printBFS()
    {
        for (int i = 0; i < N; i++)
            cout << nodes[i].value << " ";
    }
};

int main()
{
    Tree tree(4);
    tree.addNode(1, 2, 3, 0);
    tree.addNode(2, -1, 4, 1);
    tree.addNode(3, -1, -1, 2);
    tree.addNode(4, -1, -1, 3);

    tree.printBFS();

    return 0;
}
