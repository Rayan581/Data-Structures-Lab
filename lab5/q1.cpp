#include <iostream>

using namespace std;

class Stack
{
private:
    class Node
    {
    public:
        char data;
        Node *next;
    };
    Node *top;

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
    void push(char data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    // Removes and returns the element at top of stack
    char pop()
    {
        if (!isEmpty())
        {
            char data = top->data;
            Node *temp = top;
            top = top->next;

            delete temp;
            return data;
        }
    }

    // Return the top element of data
    char stackTop()
    {
        if (!isEmpty())
            return top->data;
    }

    // Prints the stack
    void printStack()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Returns if the current character is an operator
bool isOperator(char c)
{
    char operators[8] = {'+', '-', '*', '/', '^', '%', '(', ')'};

    for (int i = 0; i < 8; i++)
        if (c == operators[i])
            return true;
    return false;
}

// Returns if the precedence of one operator is higher or equal to the other
bool precedence(char op1, char op2)
{
    if (op1 == '(' || op2 == '(')
        return false;
    if (op2 == ')')
        return true;

    if (op1 == '^')
        return true;
    else if ((op1 == '%' || op1 == '/' || op1 == '*') && op2 != '^')
        return true;
    else if ((op1 == '+' || op2 == '-') && op2 != '^' && op2 != '%' && op2 != '/' && op2 != '*')
        return true;

    return false;
}

// Convert an infix string to postfix
string convertToPostfix(string infix)
{
    Stack operatorStack;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (c == ' ')
            continue;

        if (isOperator(c))
        {
            while (!operatorStack.isEmpty() && precedence(operatorStack.stackTop(), c))
                postfix += operatorStack.pop();

            if (operatorStack.isEmpty() || c != ')')
                operatorStack.push(c);
            else
                operatorStack.pop();
        }
        else
            postfix += c;
    }

    while (!operatorStack.isEmpty())
        postfix += operatorStack.pop();

    return postfix;
}

int main()
{
    string infix = "((6 + 2) * 5 - 8 / 4)";

    cout << "Original: " << infix << endl;
    cout << "Postfix: " << convertToPostfix(infix) << endl;

    return 0;
}