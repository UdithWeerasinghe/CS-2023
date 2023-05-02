#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int i)
{
    int largest = i; // assign largest is the root
    int left = 2*i + 1; // left child
    int right = 2*i + 2; // right child

    if (left < n && arr[l] > arr[largest])
        largest = left;

    if (r < n && arr[r] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extracting elements from heap one by one
    for (int i=n-1; i>=0; i--)
    {
        // moving the current root to end
        swap(arr[0], arr[i]);

        // calling the max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    int n;
    cout << "Enter the element count of the array: ";
    cin >> n;

    int heap_arr[n];
    cout << "Enter the elements of the array seperated by space: ";
    for (int i = 0; i < n; i++) {
        cin >> heap_arr[i];
    }

    cout << "Input array: ";
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array: ";
    displayArray(heap_arr, n);

    return 0;
}
