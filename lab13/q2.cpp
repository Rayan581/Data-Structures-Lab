#include <iostream>

using namespace std;

// Function to make an adjacency matrix of the given array
void adjacencyMatrix(int arr[][2], int n, int N)
{
    int **adjMatrix = new int *[N];
    for (int i = 0; i < N; i++)
    {
        adjMatrix[i] = new int[N];
        for (int j = 0; j < N; j++)
            adjMatrix[i][j] = 0;
    }

    // Forming adjacency matrix
    for (int i = 0; i < n; i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];

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
    int arr[15][2] = {{0, 1}, {0, 6}, {0, 8}, {1, 4}, {1, 6}, {1, 9}, {2, 4}, {2, 6}, {3, 4}, {3, 5}, {3, 8}, {4, 5}, {4, 9}, {7, 8}, {7, 9}};

    adjacencyMatrix(arr, 15, 10);
    return 0;
}
