#include <iostream>

using namespace std;

class Hash
{
private:
    int *arr;
    int size;
    int capacity;

    int hashFunction(int key)
    {
        return key % 7;
    }

public:
    Hash(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++)
            arr[i] = -1;
    }

    // Insert an element in the hash table
    void insert(int key)
    {
        if (size == capacity)
        {
            cout << "Hash table is full!" << endl;
            return;
        }

        int idx = hashFunction(key) % capacity;

        for (int i = 1; i <= capacity; i++)
        {
            if (arr[idx] == -1)
            {
                arr[idx] = key;
                size++;
                return;
            }
            idx = idx + (i * i);
        }
        cout << "Hash table is full!" << endl;
    }

    // Print the element in the hash table
    void print()
    {
        cout << "Hash Table: ";
        for (int i = 0; i < capacity; i++)
            if (arr[i] != -1)
                cout << arr[i] << " ";
            else
                cout << "- ";
        cout << endl;
    }
};

int main()
{
    Hash hashTable(7);

    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);
    hashTable.insert(40);

    hashTable.print();

    return 0;
}
