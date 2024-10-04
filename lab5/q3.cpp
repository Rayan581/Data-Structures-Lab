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

// Evaluates the operation between two operands
int evaluate(int oper1, int oper2, char op)
{
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
    }
}

// Evaluates the postfix expression
int evaluatePostfix(string expression)
{
    Stack operandStack;
    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (!isOperator(c))
            operandStack.push(c);
        else
        {
            int operand2 = operandStack.pop() - '0';
            int operand1 = operandStack.pop() - '0';

            operandStack.push(evaluate(operand1, operand2, c) + '0');
        }
    }

    return operandStack.pop() - '0';
}

int main()
{
    string expression = "62+5*84/-";

    cout << evaluatePostfix(expression) << endl;
    return 0;
}