#include <iostream>

using namespace std;

class Hash
{
private:
    int *hashArr;
    int size;
    int capacity;

    // Hash Function
    int hashFunction(int key)
    {
        int index = key % 10;

        while (hashArr[index] != -1)
            index = (index + 1) % capacity;

        return index;
    }

public:
    Hash(int cap)
    {
        hashArr = new int[cap];
        size = 0;
        capacity = cap;
        for (int i = 0; i < cap; i++)
            hashArr[i] = -1;
    }

    // Insert a new element into the hash table
    void insert(int key)
    {
        if (size == capacity)
        {
            cout << "Hash table is full. Cannot insert " << key << "." << endl;
            return;
        }

        int index = hashFunction(key) % capacity;
        hashArr[index] = key;
        size++;
    }

    // Print the elements of the hash table
    void print()
    {
        cout << "Hash table: ";
        for (int i = 0; i < capacity; i++)
            if (hashArr[i] != -1)
                cout << hashArr[i] << " ";
            else
                cout << "- ";
        cout << endl;
    }
};

int main()
{
    Hash hashTable(11);

    hashTable.insert(12);
    hashTable.insert(22);
    hashTable.insert(32);
    hashTable.insert(42);
    hashTable.insert(64);
    hashTable.insert(72);
    hashTable.insert(82);
    hashTable.insert(92);
    hashTable.insert(102);
    hashTable.insert(112);
    hashTable.insert(122);

    hashTable.insert(52);

    hashTable.print();

    return 0;
}
