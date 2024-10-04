#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int countTriplets(int arr[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            for (int k = j + 1; k < size; k++)
                count++;

    return count;
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int arrL[n1];
    int arrR[n2];

    for (int i = 0; i < n1; i++)
        arrL[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        arrR[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (arrL[i] <= arrR[j])
        {
            arr[k] = arrL[i];
            i++;
        }
        else
        {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = arrL[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int binarySearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left = (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    fstream file;
    file.open("data_100.txt", ios::in);

    int size;
    file >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        file >> arr[i];
    }

    file.close();

    cout << "Original Array: " << endl;
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    auto start = high_resolution_clock::now();
    int max = findMax(arr, size);
    auto stop = high_resolution_clock::now();
    auto findMaxDuration = duration_cast<milliseconds>(stop - start);
    cout << "Max value in the array is: " << max << endl;
    cout << endl;

    start = high_resolution_clock::now();
    selectionSort(arr, size);
    stop = high_resolution_clock::now();
    auto selectionSortDuration = duration_cast<milliseconds>(stop - start);
    
    cout << "The array after sorting is: " << endl;
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    start = high_resolution_clock::now();
    int count = countTriplets(arr, size);
    stop = high_resolution_clock::now();
    auto countTripletsDuration = duration_cast<milliseconds>(stop - start);
    cout << "Number of triplets in the array is: " << count << endl;
    cout << endl;

    start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    stop = high_resolution_clock::now();
    auto mergeSortDuration = duration_cast<milliseconds>(stop - start);

    cout << "The array after sorting is: " << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    start = high_resolution_clock::now();
    int num = binarySearch(arr, size, 1096);
    stop = high_resolution_clock::now();
    auto binarySearchDuration = duration_cast<milliseconds>(stop - start);
    if(num == -1)
        cout << "Number not found" << endl;
    else
        cout << "Number found at index " << num << endl;
    cout << endl;

    ofstream result("result.txt");
    fstream resultFile;
    resultFile.open("result.txt", ios::app);

    resultFile << "Size O(logn) O(n) O(nlogn) O(n^2) O(n^3)\n";
    resultFile << size << " " << binarySearchDuration.count() << " " << findMaxDuration.count() << " " << mergeSortDuration.count() << " " << selectionSortDuration.count() << " " << countTripletsDuration.count() << endl;
    delete[] arr;

    file.open("data_1000.txt", ios::in);

    size;
    file >> size;

    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        file >> arr[i];
    }

    file.close();

    start = high_resolution_clock::now();
    max = findMax(arr, size);
    stop = high_resolution_clock::now();
    findMaxDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    selectionSort(arr, size);
    stop = high_resolution_clock::now();
    selectionSortDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    count = countTriplets(arr, size);
    stop = high_resolution_clock::now();
    countTripletsDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    stop = high_resolution_clock::now();
    mergeSortDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    num = binarySearch(arr, size, 1096);
    stop = high_resolution_clock::now();
    binarySearchDuration = duration_cast<milliseconds>(stop - start);

    resultFile << size << " " << binarySearchDuration.count() << " " << findMaxDuration.count() << " " << mergeSortDuration.count() << " " << selectionSortDuration.count() << " " << countTripletsDuration.count() << endl;
    delete[] arr;

    file.open("data_5000.txt", ios::in);

    size;
    file >> size;

    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        file >> arr[i];
    }

    file.close();

    start = high_resolution_clock::now();
    max = findMax(arr, size);
    stop = high_resolution_clock::now();
    findMaxDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    selectionSort(arr, size);
    stop = high_resolution_clock::now();
    selectionSortDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    count = countTriplets(arr, size);
    stop = high_resolution_clock::now();
    countTripletsDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    stop = high_resolution_clock::now();
    mergeSortDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    num = binarySearch(arr, size, 1096);
    stop = high_resolution_clock::now();
    binarySearchDuration = duration_cast<milliseconds>(stop - start);

    resultFile << size << " " << binarySearchDuration.count() << " " << findMaxDuration.count() << " " << mergeSortDuration.count() << " " << selectionSortDuration.count() << " " << countTripletsDuration.count() << endl;

    delete[] arr;
    file.open("data_10000.txt", ios::in);

    size;
    file >> size;

    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        file >> arr[i];
    }

    file.close();

    start = high_resolution_clock::now();
    max = findMax(arr, size);
    stop = high_resolution_clock::now();
    findMaxDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    selectionSort(arr, size);
    stop = high_resolution_clock::now();
    selectionSortDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    count = countTriplets(arr, size);
    stop = high_resolution_clock::now();
    countTripletsDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    stop = high_resolution_clock::now();
    mergeSortDuration = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    num = binarySearch(arr, size, 1096);
    stop = high_resolution_clock::now();
    binarySearchDuration = duration_cast<milliseconds>(stop - start);

    resultFile << size << " " << binarySearchDuration.count() << " " << findMaxDuration.count() << " " << mergeSortDuration.count() << " " << selectionSortDuration.count() << " " << countTripletsDuration.count() << endl;
    delete[] arr;

    return 0;
}