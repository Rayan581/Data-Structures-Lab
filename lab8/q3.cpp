#include <iostream>

using namespace std;

class Tree
{
private:
    struct Node
    {
        char data;
        Node *left;
        Node *right;
    };
    Node *root;

    class Stack
    {
        struct stackNode
        {
            Node *data;
            stackNode *next;
        };
        stackNode *top;

    public:
        Stack()
        {
            top = NULL;
        }

        // Returns if the stack is empty
        bool isEmpty()
        {
            return top == NULL;
        }

        // Adds a new element at top of stack
        void push(Node *data)
        {
            stackNode *newNode = new stackNode;
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }

        // Removes and returns the element at top of stack
        Node *pop()
        {
            if (!isEmpty())
            {
                Node *data = top->data;
                stackNode *temp = top;
                top = top->next;
                delete temp;
                return data;
            }
        }

        // Return the top element of data
        Node *peek()
        {
            return top->data;
        }
    };

public:
    Tree()
    {
        root = NULL;
    }

    // Return the root of tree
    Node *getRoot()
    {
        return root;
    }

    // Return if the node is a leaf
    bool isLeaf(Node *node)
    {
        return node->left == NULL && node->right == NULL;
    }

    // Convert an expression to a tree
    bool isOperator(char c)
    {
        char operators[4] = {'+', '-', '*', '/'};
        for (int i = 0; i < 4; i++)
        {
            if (c == operators[i])
                return true;
        }
        return false;
    }

    void createTree(string exp)
    {
        Stack s;

        for (int i = 0; i < exp.length(); i++)
        {
            if (!isOperator(exp[i]))
            {
                Node *newNode = new Node;
                newNode->data = exp[i];
                newNode->left = NULL;
                newNode->right = NULL;
                s.push(newNode);
            }
            if (isOperator(exp[i]))
            {
                Node *newNode = new Node;
                newNode->data = exp[i];
                newNode->right = s.pop();
                newNode->left = s.pop();
                s.push(newNode);
            }
        }
        root = s.pop();
    }

    // Print the tree in inorder traversal
    void printInorder(Node *node)
    {
        if (node == NULL)
            return;

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    // Print the tree in postorder traversal
    void printPostorder(Node *node)
    {
        if (node == NULL)
            return;

        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }

    // Print the tree in preorder traversal
    void printPreorder(Node *node)
    {
        if (node == NULL)
            return;

        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    // Evaluate the tree
    int evaluate(Node *node)
    {
        if (isLeaf(node))
            return node->data - '0';
        else
        {
            int oper1 = evaluate(node->left);
            int oper2 = evaluate(node->right);
            char op = node->data;
            switch (op)
            {
            case '+':
                return oper1 + oper2;
            case '-':
                return oper1 - oper2;
            case '*':
                return oper1 * oper2;
            case '/':
                return oper1 / oper2;
            default:
                return 0;
            }
        }
        return 0;
    }
};

int main()
{
    Tree t;
    t.createTree("223*+4/");

    t.printInorder(t.getRoot());
    cout << endl;
    t.printPostorder(t.getRoot());
    cout << endl;
    t.printPreorder(t.getRoot());
    cout << endl;

    cout << t.evaluate(t.getRoot()) << endl;

    return 0;
}