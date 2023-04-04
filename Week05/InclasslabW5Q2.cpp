#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quick_sort(vector<int>& arr, int left, int right);
int partition(vector<int>& arr, int left, int right, int pivot_index);
void print_array(vector<int>& arr, int size);
double find_median(vector<int>& arr);

int main()
{
    vector<int> arr;
    int n;

    cout << "Enter the length of the array: ";
    cin >> n;

    cout << "Enter the numbers in the array: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);

        quick_sort(arr, 0, i); // sorting the array step by step
        cout << "Sorted array for this time instance: ";
        print_array(arr, i+1); // get the currently sorted array

        double median = find_median(arr); // check out the running median
        cout << "Running Median: " << median << endl;
    }

    return 0;
}

void quick_sort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int pivot_index = left + (right - left) / 2;
        int pivot_new_index = partition(arr, left, right, pivot_index);
        quick_sort(arr, left, pivot_new_index - 1);
        quick_sort(arr, pivot_new_index + 1, right);
    }
}

int partition(vector<int>& arr, int left, int right, int pivot_index)
{
    int pivot_val = arr[pivot_index];
    swap(arr[pivot_index], arr[right]); // Moving pivot to the tail
    int stored_index = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivot_val) {
            swap(arr[i], arr[stored_index]);
            stored_index++;
        }
    }
    swap(arr[stored_index], arr[right]); // Move pivot to the end destination of it
    return stored_index;
}

void print_array(vector<int>& arr, int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double find_median(vector<int>& arr)
{
    int n = arr.size();
    if (n % 2 == 0) {
        return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        return (double)arr[n / 2];
    }
}