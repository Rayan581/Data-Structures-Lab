#include <iostream>

using namespace std;

class DoublyList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Addds an element in the list
    void append(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Removes the last element in the list
    int pop_back()
    {
        if (head == nullptr)
            return -1;

        int data;
        if (head == tail)
        {
            data = head->data;
            delete head;
            head = tail = nullptr;
        }
        else
        {
            data = tail->data;
            Node *temp = tail;
            tail = tail->prev;
            delete temp;
        }

        return data;
    }

    // Removes the first element in the list
    int pop_front()
    {
        if (head == nullptr)
            return -1;

        int data;
        if (head == tail)
        {
            data = head->data;
            delete head;
            head = tail = nullptr;
        }
        else
        {
            data = head->data;
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        return data;
    }

    // Returns if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Prints the elements in the list
    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(10);
    list.append(11);
    list.append(12);

    cout << "Original List: " << endl;
    list.print();

    DoublyList evenList;
    DoublyList oddList;

    while (!list.isEmpty())
    {
        int data = list.pop_front();
        if (data % 2)
            oddList.append(data);
        else
            evenList.append(data);
    }

    cout << "Even data: " << endl;
    evenList.print();
    cout << "Odd data: " << endl;
    oddList.print();

    return 0;
}