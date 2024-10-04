#include <iostream>
#include <ctime>

using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

int findMax(int *arr, int size)
{
    int max = *arr;

    for (int i = 0; i < size; i++)
        if (*(arr + i) > max)
            max = *(arr + i);

    return max;
}

int findMin(int *arr, int size)
{
    int min = *arr;

    for (int i = 0; i < size; i++)
        if (*(arr + i) < min)
            min = *(arr + i);

    return min;
}

int main()
{
    srand(time(nullptr));
    int size = rand() % 10 + 3;

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        *(arr + i) = rand() % 50;

    cout << "Array: ";
    printArray(arr, size);

    cout << "Largest Element: " << findMax(arr, size) << endl;
    cout << "Smallest Element: " << findMin(arr, size) << endl;

    return 0;
}