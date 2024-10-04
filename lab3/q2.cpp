#include <iostream>

using namespace std;

template <typename var>
class ResizableArray
{
private:
    var *list;
    int Size;
    int Capacity;

public:
    ResizableArray()
    {
        list = new var[1];
        Size = 0;
        Capacity = 1;
    }

    void add(var value)
    {
        if (Size < Capacity)
        {
            list[Size] = value;
            Size++;
        }
        else
        {
            Capacity *= 2;

            var *temp = new var[Size];
            for (int i = 0; i < Size; i++)
                temp[i] = list[i];

            delete[] list;
            list = new var[Capacity];
            for (int i = 0; i < Size; i++)
                list[i] = temp[i];

            list[Size] = value;
            Size++;

            delete[] temp;
        }
    }

    bool insert(int index, var value)
    {
        if (index < 0 || index > Size)
            return false;

        if (index < Size)
        {
            if (Size != Capacity)
            {
                for (int i = Size; i > index; i--)
                    list[i] = list[i - 1];
                list[index] = value;
                Size++;
            }
            else if (Size == Capacity)
            {
                Capacity *= 2;

                var *temp = new var[Size];
                for (int i = 0; i < Size; i++)
                    temp[i] = list[i];

                delete[] list;
                list = new var[Capacity];
                for (int i = 0; i < Size; i++)
                    list[i] = temp[i];

                for (int i = Size; i > index; i--)
                    list[i] = list[i - 1];
                list[index] = value;
                Size++;
            }
        }
        else
            add(value);
    }

    bool remove(int index)
    {
        if (index < 0 || index >= Size)
            return false;

        for (int i = index; i < Size - 1; i++)
            list[i] = list[i + 1];
        Size--;

        if (Size <= static_cast<float>(Capacity) / 4)
            Capacity /= 2;
    }

    bool update(int index, int value)
    {
        if (index < 0 || index >= Size)
            return false;
        list[index] = value;
    }

    int get(int index) const
    {
        if (index < 0 || index >= Size)
            return -1;

        return list[index];
    }

    int size()
    {
        return Size;
    }

    int capacity()
    {
        return Capacity;
    }

    void clear()
    {
        delete[] list;
        Size = 0;
        list = new var[Capacity];
    }

    void reverse()
    {
        for (int i = 0, j = Size - 1; i < j; i++, j--)
        {
            var temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }

    int find(var value) const
    {
        for (int i = 0; i < Size; i++)
            if (list[i] == value)
                return i;

        return -1;
    }

    void print()
    {
        cout << "Array: " << endl;
        for (int i = 0; i < Size; i++)
            cout << list[i] << " ";
        cout << endl;
    }
};

int main()
{
    ResizableArray<int> arr;
    arr.add(5);
    arr.add(9);
    arr.add(0);
    arr.add(8);
    arr.insert(4, 10);
    arr.print();
    arr.remove(3);
    arr.print();
    cout << arr.capacity() << endl;

    arr.reverse();

    arr.print();

    return 0;
}