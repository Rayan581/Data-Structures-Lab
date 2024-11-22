#include <iostream>
#include <ctime>

using namespace std;

class Hash
{
private:
    int *arr;
    int size;
    int capacity;
    int *randomArray;

    int hashFunction(int key)
    {
        return key % 13;
    }

public:
    Hash(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++)
            arr[i] = -1;

        randomArray = new int[capacity];
        srand(time(0));
        for (int i = 0; i < capacity; i++)
            randomArray[i] = rand() % 100;

        int idx = rand() % capacity;
        randomArray[idx] = 3;
        idx = rand() % capacity;
        randomArray[idx] = 5;
        idx = rand() % capacity;
        randomArray[idx] = 7;
    }

    // Insert an element in the hash table
    void insert(int key)
    {
        if (size == capacity)
        {
            cout << "Hash table is full!" << endl;
            return;
        }

        int i = 0;
        int idx = hashFunction(key) % capacity;
        while (arr[idx] != -1)
            idx = (idx + randomArray[i++]) % capacity;

        arr[idx] = key;
        size++;
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

    hashTable.insert(15);
    hashTable.insert(28);
    hashTable.insert(41);
    hashTable.insert(54);

    hashTable.print();

    return 0;
}
