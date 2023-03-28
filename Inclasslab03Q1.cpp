#include <iostream>
#include <chrono>
#include <random>
#include <stack>
#include <vector>

using namespace std;

//01. Implementation of Recursive Quick Sort algorithm
void recursiveQuicksort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    int indexPivot = i + 1;
    swap(arr[indexPivot], arr[right]);

    recursiveQuicksort(arr, left, indexPivot - 1);
    recursiveQuicksort(arr, indexPivot + 1, right);
}

//02. Implementation of the Non-Recursive Quick Sort algorithm
void nonrecursiveQuicksort(vector<int>& arr) {
    stack<pair<int, int>> st;
    st.push({0, arr.size() - 1});

    while (!st.empty()) {
        int left = st.top().first;
        int right = st.top().second;
        st.pop();

        if (left >= right) {
            continue;
        }

        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        int indexPivot = i + 1;
        swap(arr[indexPivot], arr[right]);

        st.push({left, indexPivot - 1});
        st.push({indexPivot + 1, right});
    }
}

int main() {
    // initializing random number generation
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(1, 1000);

    // generating and sorting random sized arrays
    for (int n = 10000; n <= 100000; n += 10000) {
        vector<int> arr(n);

        // adding random values for generated arrays
        for (int i = 0; i < n; i++) {
            arr[i] = dist(rng);
        }

        // sorting with Recursive Quick Sort algorithm and find the time taken
        auto startTime = chrono::steady_clock::now();
        recursiveQuicksort(arr, 0, n - 1);
        auto endTime = chrono::steady_clock::now();
        auto recursiveTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

        // sorting with Non-Recursive Quick Sort algorithm and find the time taken
        startTime = chrono::steady_clock::now();
        nonrecursiveQuicksort(arr);
        endTime = chrono::steady_clock::now();
        auto nonrecursiveTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

        // Print obtained times
        cout << "Array Length: " << n << endl;
        cout << "Time taken by Recursive Quick Sort : " << recursiveTime << " ms" << endl;
        cout << "Time taken by Non-Recursive Quick Sort: " << nonrecursiveTime << " ms" << endl;
        cout << endl;
    }

    return 0;
}
