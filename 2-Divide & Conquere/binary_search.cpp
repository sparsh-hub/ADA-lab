#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

int binarySearch(vector<int>& arr, int left, int right, int key) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
        return mid;
    } 
    else if (key < arr[mid]) {
        return binarySearch(arr, left, mid - 1, key);
    } 
    else {
        return binarySearch(arr, mid + 1, right, key);
    }
}

int main() {
    int n;
    cin >> n;
    int t = n;

    vector<long long> durationArray(n + 1);

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int size = n;

        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        int key = size; 

        auto start = chrono::high_resolution_clock::now();
        binarySearch(arr, 0, size - 1, key);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        durationArray[n] = duration.count();

        cout << "     " << n
             << "         ->      "
             << duration.count()
             << " nanoseconds" << endl;

        n--;
    }

    long long sum = 0;
    for (auto time : durationArray) {
        sum += time;
    }

    long long avg = sum / t;
    cout << "the average time taken to execute the program is "
         << avg << " nanoseconds";

    return 0;
}