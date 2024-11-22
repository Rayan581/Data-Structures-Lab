#include <iostream>

using namespace std;

class MaxHeap
{
private:
    int *heapArray;
    int capacity;

    // Task 3:
    // Heapify the heap after insertion
    void heapifyInsert(int index)
    {
        if (heapArray[index] < heapArray[index / 2] || index / 2 < 1)
            return;

        int parent = index / 2;

        if (heapArray[parent] < heapArray[index])
        {
            int temp = heapArray[parent];
            heapArray[parent] = heapArray[index];
            heapArray[index] = temp;

            heapifyInsert(parent);
        }
    }

    // Heapify the heap after removal
    void heapifyRemove(int index)
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int largest = index;

        if (left <= heapArray[0] && heapArray[left] > heapArray[largest])
            largest = left;

        if (right <= heapArray[0] && heapArray[right] > heapArray[largest])
            largest = right;

        if (largest != index)
        {
            int temp = heapArray[index];
            heapArray[index] = heapArray[largest];
            heapArray[largest] = temp;
            heapifyRemove(largest);
        }
    }

public:
    MaxHeap(int cap)
    {
        heapArray = new int[cap + 1];
        capacity = cap;
        heapArray[0] = 0;
    }

    // Returns the size
    int size()
    {
        return heapArray[0];
    }

    bool isFull()
    {
        return heapArray[0] == capacity;
    }

    // Task 1:
    // Insert an element into the heap
    void insert(int value)
    {
        if (isFull())
        {
            cout << "Heap is full!" << endl;
            return;
        }

        heapArray[heapArray[0]++ + 1] = value;
        heapifyInsert(heapArray[0]);
    }

    // Task 2:
    // Remove and return the maximum element from the heap
    int removeMax()
    {
        if (heapArray[0] == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int max = heapArray[1];
        heapArray[1] = heapArray[heapArray[0]--];
        heapifyRemove(1);
        return max;
    }

    // Task 5:
    // Merge two heaps
    MaxHeap mergeHeaps(MaxHeap heap1, MaxHeap heap2)
    {
        MaxHeap mergedHeap(heap1.capacity + heap2.capacity);

        for (int i = 1; i <= heap1.heapArray[0]; i++)
            mergedHeap.insert(heap1.heapArray[i]);

        for (int i = 1; i <= heap2.heapArray[0]; i++)
            mergedHeap.insert(heap2.heapArray[i]);

        return mergedHeap;
    }

    // Task 7:
    // Print all the elements within given range
    void printRange(int start, int end)
    {
        MaxHeap temp(capacity);

        for (int i = 1; i < capacity; i++)
            temp.insert(heapArray[i]);

        while (temp.size() > 0)
        {
            int max = temp.removeMax();
            if (max >= start && max <= end)
                cout << max << " ";
        }
        cout << endl;
    }

    // Task 8:
    // Print the path to root
    void printPath(int index)
    {
        if (index <= 0 || index >= heapArray[0])
            return;

        cout << heapArray[index] << " ";
        printPath(index / 2);
    }

    // Print the heap
    void print()
    {
        for (int i = 1; i <= heapArray[0]; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }
};

class MinHeap
{
private:
    int *heapArray;
    int capacity;

    // Task 3:
    // Heapify the heap after insertion
    void heapifyInsert(int index)
    {
        if (heapArray[index] > heapArray[index / 2] || index / 2 < 1)
            return;

        int parent = index / 2;

        if (heapArray[parent] > heapArray[index])
        {
            int temp = heapArray[parent];
            heapArray[parent] = heapArray[index];
            heapArray[index] = temp;

            heapifyInsert(parent);
        }
    }

    // Heapify the heap after removal
    void heapifyRemove(int index)
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int smallest = index;

        if (left <= heapArray[0] && heapArray[left] < heapArray[smallest])
            smallest = left;

        if (right <= heapArray[0] && heapArray[right] < heapArray[smallest])
            smallest = right;

        if (smallest != index)
        {
            int temp = heapArray[index];
            heapArray[index] = heapArray[smallest];
            heapArray[smallest] = temp;
            heapifyRemove(smallest);
        }
    }

    void removeMax()
    {
        if (heapArray[0] == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        int max = heapArray[1];
        int i = 0;
        while (i * 2 <= heapArray[0])
        {
            if(heapArray[i * 2] > heapArray[i * 2 + 1])
            {
                
            }
        }
    }

public:
    MinHeap(int cap)
    {
        heapArray = new int[cap + 1];
        capacity = cap;
        heapArray[0] = 0;
    }

    bool isFull()
    {
        return heapArray[0] == capacity;
    }

    // Task 1:
    // Insert an element into the heap
    void insert(int value)
    {
        if (isFull())
        {
            cout << "Heap is full!" << endl;
            return;
        }

        heapArray[heapArray[0]++ + 1] = value;
        heapifyInsert(heapArray[0]);
    }

    // Task 2:
    // Remove and return the minimum element from the heap
    int removeMin()
    {
        if (heapArray[0] == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int min = heapArray[1];
        heapArray[1] = heapArray[heapArray[0]--];
        heapifyRemove(1);
    }

    // Task 6:
    // Peek at the minimum element from the heap
    int peek()
    {
        if (heapArray[0] == 0)
        {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        return heapArray[1];
    }

    // Task 4:
    // Find Kth largest element from the minHeap
    int kthLargest(int k)
    {
        if (k > heapArray[0])
        {
            cout << "K is greater than the number of elements in the heap!" << endl;
            return -1;
        }

        MinHeap minHeap(heapArray[0]);

        for (int i = 1; i <= heapArray[0]; i++)
            minHeap.insert(heapArray[i]);

        for (int i = 1; i < k; i++)
        {
            minHeap.removeMin();
        }

        return minHeap.removeMin();
    }

    // Print the heap
    void print()
    {
        for (int i = 1; i <= heapArray[0]; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }
};

// Task 6:
// Sort an array in ascending order
int *array_sort(int *arr, int size)
{
    MaxHeap heap(size);
    for (int i = 0; i < size; i++)
        heap.insert(arr[i]);

    heap.print();

    int *sortedArray = new int[size];
    for (int i = size - 1; i >= 0; i--)
        sortedArray[i] = heap.removeMax();

    return sortedArray;
}

int main()
{
    MaxHeap heap1(6);
    MaxHeap heap2(4);

    heap1.insert(5);
    heap1.insert(3);
    heap1.insert(8);
    heap1.insert(2);
    heap1.insert(9);
    heap1.insert(1);

    heap1.print();

    heap1.printPath(3);

    // heap2.insert(4);
    // heap2.insert(7);
    // heap2.insert(6);

    // MaxHeap mergedHeap(7);
    // mergedHeap = heap1.mergeHeaps(heap1, heap2);

    // cout << "Heap 1: ";
    // heap1.print();
    // cout << "Heap 2: ";
    // heap2.print();
    // cout << "Merged Heap: ";
    // mergedHeap.print();

    return 0;
}