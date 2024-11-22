#include <iostream>

using namespace std;

class Hash
{
private:
    class List
    {
    private:
        struct Node
        {
            int data;
            Node *next;
        };
        Node *head;

    public:
        List()
        {
            head = nullptr;
        }

        void insert(int data)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }

        void display()
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    };

    List *arr;
    int size;

    int hashFunction(int key)
    {
        return key % 5;
    }

public:
    Hash(int cap)
    {
        size = cap;
        arr = new List[size];
    }

    void insert(int key)
    {
        int idx = hashFunction(key) % size;
        cout << idx << endl;
        arr[idx].insert(key);
    }

    void display()
    {
        cout << "Hash Table: ";
        for (int i = 0; i < size; i++)
            arr[i].display();
        cout << endl;
    }
};

int main()
{
    Hash hashTable(7);

    hashTable.insert(21);
    hashTable.insert(26);
    hashTable.insert(31);
    hashTable.insert(36);

    hashTable.display();

    return 0;
}
