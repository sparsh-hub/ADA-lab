#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

int firstDuplicate(int arr[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            return arr[i];
        }
        seen.insert(arr[i]);
    }
    return -1; // no duplicate
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<int> durationArray(n + 1);

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int size = n * 1000;   
        int* arr = new int[size];

       
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
        arr[size - 1] = arr[size / 2];  

        auto start = chrono::high_resolution_clock::now();
        firstDuplicate(arr, size);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        durationArray[n] = duration.count();

        cout << "     " << n
             << "         ->      "
             << duration.count()
             << " nanoseconds" << endl;

        delete[] arr;
        n--;
    }

    int sum = 0;
    for (auto time : durationArray) {
        sum += time;
    }

    int avg = sum / t;
    cout << "the average time taken to execute the program is "
         << avg << " nanoseconds";

    return 0;
}
