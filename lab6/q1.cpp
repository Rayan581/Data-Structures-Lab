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

    // Empties the stack
    void makeNull()
    {
        while (!isEmpty())
        {
            pop();
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

    void copy(Stack other)
    {
        Node *temp = other.top;
        while (temp != NULL)
        {
            push(temp->data);
            temp = temp->next;
        }
    }
};

class Queue
{
private:
    Stack input;
    Stack output;
    int size;
    int capacity;

public:
    Queue(int cap)
    {
        capacity = cap;
        size = 0;
    }

    // Adds an element to the queue
    void enqueue(char data)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }

        input.push(data);

        output.makeNull();
        output.copy(input);
        size++;
    }

    // Removes an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        output.pop();
        input.makeNull();
        input.copy(output);
        size--;
    }

    // Returns if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Returns if the queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Displays the elements in the queue
    void displayQueue()
    {
        output.printStack();
    }
};

int main()
{
    Queue temp(5);

    temp.enqueue('A');
    temp.enqueue('B');
    temp.enqueue('C');
    temp.enqueue('D');
    temp.enqueue('E');
    temp.displayQueue();

    temp.dequeue();
    temp.dequeue();
    temp.displayQueue();

    return 0;
}