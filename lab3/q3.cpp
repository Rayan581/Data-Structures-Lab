#include <iostream>

using namespace std;

class CustomerID
{
private:
    int *ID;
    int size;

public:
    CustomerID()
    {
        ID = new int[0];
        size = 0;
    }

    void addCustomer(int customerId)
    {
        int *temp = new int[size];
        for (int i = 0; i < size; i++)
            temp[i] = ID[i];

        delete[] ID;
        ID = new int[size + 1];

        for (int i = 0; i < size; i++)
            ID[i] = temp[i];

        ID[size] = customerId;
        size++;
        delete[] temp;
    }

    int findCustomer(int customerId) const
    {
        for (int i = 0; i < size; i++)
            if (ID[i] == customerId)
                return i;
        return -1;
    }

    bool removeCustomer(int customerId)
    {
        int index = -1;
        for (int i = 0; i < size; i++)
            if (ID[i] == customerId)
                index = i;

        if (index != -1)
        {
            for (int i = index; i < size - 1; i++)
                ID[i] = ID[i + 1];
            size--;
        }

        return (index != -1);
    }

    void print()
    {
        cout << "Customers List: " << endl;
        for (int i = 0; i < size; i++)
            cout << ID[i] << endl;
        cout << endl;
    }
};

int main()
{
    CustomerID id;

    id.addCustomer(1);
    id.addCustomer(2);
    id.addCustomer(3);
    id.addCustomer(4);

    cout << id.findCustomer(1) << endl;
    cout << id.removeCustomer(2) << endl;
    id.print();

    return 0;
}