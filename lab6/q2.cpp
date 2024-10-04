#include <iostream>
#include <Windows.h>

using namespace std;

struct Data
{
    int process;
    int time;
};

class Queue
{
private:
    struct Node
    {
        Data data;
        Node *next;
    };
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Adds an element to the queue
    void enqueue(Data data)
    {
        Node *newNode = new Node;
        newNode->data.process = data.process;
        newNode->data.time = data.time;
        newNode->next = nullptr;

        if (rear == nullptr)
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Removes an element from the queue
    Data dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return Data();
        }

        Data deleted = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;

        return deleted;
    }

    // Returns if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Prints the elements in a queue
    void printQueue()
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            Sleep(temp->data.time * 1000);
            cout << temp->data.process << " completed in " << temp->data.time << " seconds" << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Queue processes;

    Data data;
    do
    {
        cout << "Enter process id: ";
        cin >> data.process;
        cout << "Enter process time: ";
        cin >> data.time;

        if (data.process != -1 && data.time != -1)
            processes.enqueue(data);

    } while (data.process != -1 && data.time != -1);

    processes.printQueue();

    return 0;
}