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

class Array
{
private:
    patient arr[20];
    int size;

public:
    Array()
    {
        size = 0;
    }

    // Adds a patient at end of queue
    void push_back(string name, int id)
    {
        if (size == 19)
        {
            cout << "Queue is already full!" << endl;
            return;
        }

        arr[size] = patient(name, id);
        size++;
    }

    // Adds a patient at start of queue
    void push_front(string name, int id)
    {
        if (size == 19)
        {
            cout << "Queue is already full!" << endl;
            return;
        }

        for (int i = size + 1; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = patient(name, id);

        size++;
    }

    // Adds a patient at a specific index
    void insert(int index, string name, int id)
    {
        if (size == 19)
        {
            cout << "Queue is already full!" << endl;
            return;
        }

        for (int i = size + 1; i > index; i--)
            arr[i] = arr[i - 1];
        arr[index] = patient(name, id);

        size++;
    }

    // Removes a patient in the beginning
    void pop_front()
    {
        if (size == 0)
        {
            cout << "Queue is already empty!" << endl;
            return;
        }

        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    // Removes a patieng in the end
    void pop_back()
    {
        if (size == 0)
        {
            cout << "Queue is already empty!" << endl;
            return;
        }

        size--;
    }

    // Removes a patient at a specific index
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of range!" << endl;
            return;
        }
        if (size == 0)
        {
            cout << "Queue is already empty!" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    // Displays all the patients
    void print()
    {
        cout << "Number of Patients in queue: " << size << endl;
        for (int i = 0; i < size; i++)
            cout << arr[i] << endl;
    }
};

int main()
{
    Array arr;

    arr.push_back("Hello", 1);
    arr.push_back("Helloasdf", 2);
    arr.push_back("He", 3);
    arr.push_back("Hel", 4);
    arr.push_front("Rayan", 0);
    arr.insert(5, "AHmed", 8);
    arr.pop_front();
    arr.pop_back();
    arr.pop_back();
    arr.pop_back();

    arr.print();

    return 0;
}