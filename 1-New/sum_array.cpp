#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

int sumOfArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<int> durationArray(n + 1);

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int size = n * 10000;  
        int* arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        auto start = chrono::high_resolution_clock::now();
        sumOfArray(arr, size);
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
