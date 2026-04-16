#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

int calculateVelocity(int distance, int time) {
    if (time == 0) {
        return 0.0;
    }
    return distance / time;
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<int> durationArray(n + 1);

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int distance = n * 1000; 
        int time = n * 10;         

        auto start = chrono::high_resolution_clock::now();
        calculateVelocity(distance, time);
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
    for (auto timeTaken : durationArray) {
        sum += timeTaken;
    }

    int avg = sum / t;
    cout << "the average time taken to execute the program is "
         << avg << " nanoseconds";

    return 0;
}
