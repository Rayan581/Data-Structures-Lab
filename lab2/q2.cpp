#include <iostream>
#include <ctime>

using namespace std;

void displayMatrix(int **arr)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << *(*(arr + i) + j) << " ";
        cout << endl;
    }
    cout << endl;
}

void clearMatrix(int **&arr)
{
    for (int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            *(*(arr + i) + j) = 0;
}

void addMatrix(int **arr1, int **arr2, int **&result)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            *(*(result + i) + j) = *(*(arr1 + i) + j) + *(*(arr2 + i) + j);
}

void multiplyMatrix(int **arr1, int **arr2, int **&result)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                *(*(result + i) + j) += *(*(arr1 + i) + k) * *(*(arr2 + k) + j);
}

int main()
{
    srand(time(nullptr));

    int **arr1 = new int *[3];
    for (int i = 0; i < 3; i++)
        *(arr1 + i) = new int[3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            *(*(arr1 + i) + j) = rand() % 20;

    int **arr2 = new int *[3];
    for (int i = 0; i < 3; i++)
        *(arr2 + i) = new int[3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            *(*(arr2 + i) + j) = rand() % 20;

    cout << "Array 1: " << endl;
    displayMatrix(arr1);

    cout << "Array 2: " << endl;
    displayMatrix(arr2);

    int **result = new int *[3];
    for (int i = 0; i < 3; i++)
        *(result + i) = new int[3];

    addMatrix(arr1, arr2, result);
    cout << "Addition: " << endl;
    displayMatrix(result);

    clearMatrix(result);

    multiplyMatrix(arr1, arr2, result);
    cout << "Multiplication: " << endl;
    displayMatrix(result);

    return 0;
}