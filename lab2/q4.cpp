#include <iostream>
#include <ctime>

using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

void bubbleSort(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (*(arr + j) > *(arr + j + 1))
            {
                *(arr + j) = *(arr + j) + *(arr + j + 1);
                *(arr + j + 1) = *(arr + j) - *(arr + j + 1);
                *(arr + j) = *(arr + j) - *(arr + j + 1);
            }
}

int main()
{
    srand(time(nullptr));
    int size = rand() % 10 + 3;

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        *(arr + i) = rand() % 50;

    cout << "Original Array: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "Sorted Array: ";
    printArray(arr, size);

    return 0;
}