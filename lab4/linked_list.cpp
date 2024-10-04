#include <iostream>

using namespace std;

class patient
{
private:
    string name;
    int id;

public:
    patient()
    {
        name = "";
        id = 0;
    }
    patient(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    friend ostream &operator<<(ostream &output, const patient &other)
    {
        output << "Name: " << other.name << endl;
        output << "ID: " << other.id << endl;
    }
};

struct Node
{
    patient data;
    Node *next;
};

class List
{
private:
    Node *head;

public:
    List() { head = NULL; }

    // Adds a patient at the end of the list
    void push_back(string name, int id)
    {
        Node *newNode = new Node();
        newNode->data = patient(name, id);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
        {
            Node *last = head;
            while (last->next != NULL)
                last = last->next;
            last->next = newNode;
        }
    }

    // Adds a patient at the start of the list
    void push_front(string name, int id)
    {
        Node *newNode = new Node();
        newNode->data = patient(name, id);

        newNode->next = head;
        head = newNode;
    }

    // Inserts a patient at a specific index
    void insert(int index, string name, int id)
    {
        if (index == 0)
        {
            push_front(name, id);
            return;
        }

        Node *newNode = new Node();
        newNode->data = patient(name, id);
        Node *current = head;
        int currentIndex = 0;

        while (current != NULL && currentIndex < index - 1)
        {
            current = current->next;
            currentIndex++;
        }

        if (current == NULL)
            cout << "Index out of range" << endl;
        else
        {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Removes a patient in the end
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *current = head;
        while (current->next->next != NULL)
            current = current->next;

        delete current->next;
        current->next = NULL;
    }

    // Removes a patient in the beginning
    void pop_front()
    {
        if (head == NULL)
            cout << "List is empty" << endl;
        else
        {
            Node *temp = head;
            head = head->next;

            delete temp;
        }
    }

    // Removes a patient at a specific index
    void remove(int index)
    {
        if (index < 0)
        {
            cout << "Index out of range" << endl;
            return;
        }

        if (index == 0)
        {
            pop_front();
            return;
        }

        Node *current = head;
        int currentIndex = 0;

        while (current != NULL && currentIndex < index - 1)
        {
            current = current->next;
            currentIndex++;
        }

        if (current == NULL || current->next == NULL)
        {
            cout << "Index out of range" << endl;
            return;
        }

        Node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Displays all the patients
    void print()
    {
        Node *current = head;

        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main()
{
    List list;

    list.push_back("Ryaan", 1);
    list.push_back("Ryaan", 2);
    list.push_back("Ryaan", 3);
    list.push_front("ahmed", 2);
    list.pop_back();
    list.pop_front();
    list.remove(1);

    list.print();

    return 0;
}