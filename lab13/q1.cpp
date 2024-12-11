#include <iostream>

using namespace std;

// Function to make an adjacency matrix of the given array
void adjacencyMatrix(int arr[][2], int N, int M)
{
    int **adjMatrix = new int *[N];
    for (int i = 0; i < N; i++)
    {
        adjMatrix[i] = new int[N];
        for (int j = 0; j < N; j++)
            adjMatrix[i][j] = 0;
    }

    // Forming adjacency matrix
    for (int i = 0; i < M; i++)
    {
        int x = arr[i][0] - 1;
        int y = arr[i][1] - 1;

        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    // Printing adjacency matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[7][2] = {{1, 2},
                     {2, 3},
                     {4, 5},
                     {1, 5},
                     {6, 1},
                     {7, 4},
                     {3, 8}};

    adjacencyMatrix(arr, 8, 7);
    return 0;
}
