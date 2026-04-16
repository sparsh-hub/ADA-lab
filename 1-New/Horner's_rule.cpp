#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

int hornersRule(int coeff[], int n, int x) {
    int result = coeff[n];
    for (int i = n - 1; i >= 0; i--) {
        result = result * x + coeff[i];
    }
    return result;
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<int> durationArray(n + 1);
    int x = 2.5;

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int degree = n * 1000;   
        int* coeff = new int[degree + 1];

        for (int i = 0; i <= degree; i++) {
            coeff[i] = 1.5;
        }

        auto start = chrono::high_resolution_clock::now();
        hornersRule(coeff, degree, x);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        durationArray[n] = duration.count();

        cout << "     " << n
             << "         ->      "
             << duration.count()
             << " nanoseconds" << endl;

        delete[] coeff;
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
