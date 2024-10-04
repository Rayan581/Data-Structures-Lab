#include <iostream>

using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

void appendValue(int *&arr, int size, int num)
{
    int *temp = new int[size];

    for (int i = 0; i < size; i++)
        *(temp + i) = *(arr + i);

    delete[] arr;
    arr = new int[size + 1];

    for (int i = 0; i < size + 1; i++)
        *(arr + i) = *(temp + i);

    *(arr + size) = num;

    delete[] temp;
}

void swapArrays(int *&arr1, int &size1, int *&arr2, int &size2)
{
    int *temp = new int[size1];

    for (int i = 0; i < size1; i++)
        *(temp + i) = *(arr1 + i);

    delete[] arr1;
    arr1 = new int[size2];

    for (int i = 0; i < size2; i++)
        *(arr1 + i) = *(arr2 + i);

    delete[] arr2;
    arr2 = new int[size1];

    for (int i = 0; i < size1; i++)
        *(arr2 + i) = *(temp + i);

    size1 = size1 + size2;
    size2 = size1 - size2;
    size1 = size1 - size2;

    delete[] temp;
}

int main()
{
    int *arr1 = nullptr, *arr2 = nullptr;
    int size1 = 0, size2 = 0;

    cout << "Array 1: " << endl;
    for (size1; true; size1++)
    {
        int num;

        cout << "Enter a number(Enter a negative value to quit): ";
        cin >> num;

        if (num < 0)
            break;

        appendValue(arr1, size1, num);
    }

    cout << "Array 2: " << endl;
    for (size2; true; size2++)
    {
        int num;

        cout << "Enter a number(Enter a negative value to quit): ";
        cin >> num;

        if (num < 0)
            break;

        appendValue(arr2, size2, num);
    }

    cout << "Original Arrays: " << endl;
    cout << "Array 1: ";
    printArray(arr1, size1);
    cout << "Array 2: ";
    printArray(arr2, size2);

    swapArrays(arr1, size1, arr2, size2);
    cout << "Swapped Arrays: " << endl;
    cout << "Array 1: ";
    printArray(arr1, size1);
    cout << "Array 2: ";
    printArray(arr2, size2);

    delete[] arr1;
    delete[] arr2;

    return 0;
}