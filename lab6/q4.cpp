#include <iostream>

using namespace std;

class Queue
{
private:
    struct Node
    {
        string data;
        Node *next;
    };
    Node *front;
    Node *rear;
    int capacity;
    int size;

public:
    Queue(int cap)
    {
        front = nullptr;
        rear = nullptr;
        capacity = cap;
        size = 0;
    }

    // Adds an element to the queue
    void AddCustomer(string data)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }

        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        cout << "Added " << data << " to the queue." << endl;

        if (rear == nullptr)
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Removes an element from the queue
    string AttendCustomer()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return "";
        }

        string deleted = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        size--;

        cout << deleted << " has been attended and removed from the queue." << endl;

        if (front == nullptr)
            rear = nullptr;

        return deleted;
    }

    // Returns if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Returns if the queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Prints the elements in a queue
    void viewQueue()
    {
        Node *temp = front;

        cout << endl
             << "Customers in the queue: " << endl;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Queue queue(5);
    queue.AddCustomer("Brook");
    queue.AddCustomer("Sheeta");
    queue.AddCustomer("Kenta");
    queue.AttendCustomer();
    queue.AddCustomer("Lila");
    queue.AddCustomer("Hinata");

    queue.viewQueue();
    return 0;
}