#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

int findMissingNumber(int arr[], int n) {
    int totalSum = (n + 1) * (n + 2) / 2;
    int arraySum = 0;
    for (int i = 0; i < n; i++) {
        arraySum += arr[i];
    }
    return totalSum - arraySum;
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<long long> durationArray(n + 1);

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int size = n * 1000;  
        int* arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        auto start = chrono::high_resolution_clock::now();
        findMissingNumber(arr, size);
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
