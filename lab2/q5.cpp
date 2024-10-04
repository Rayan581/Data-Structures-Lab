#include <iostream>
#include <ctime>

using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

void rotateRight(int *&arr, int size, int steps)
{
    int *temp = new int[size];

    for (int i = 0, j = steps; i < size; i++, j++)
        *(temp + j % size) = *(arr + i);

    for (int i = 0; i < size; i++)
        *(arr + i) = *(temp + i);
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

    int steps;
    cout << "Enter steps: ";
    cin >> steps;

    rotateRight(arr, size, steps);
    cout << "Rotated Array: ";
    printArray(arr, size);

    return 0;
}