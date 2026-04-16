#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

int powerIterative(int x, int n) {
    int result = 1.0;
    while (n--) {
        result *= x;
    }
    return result;
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<int> durationArray(n + 1);
    int x = 2.0;

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int exponent = n * 1000;   
        auto start = chrono::high_resolution_clock::now();
        powerIterative(x, exponent);
        auto stop = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        durationArray[n] = duration.count();

        cout << "     " << n
             << "         ->      "
             << duration.count()
             << " nanoseconds" << endl;

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
