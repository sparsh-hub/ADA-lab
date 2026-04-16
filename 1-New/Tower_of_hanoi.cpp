#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<int> durationArray(n + 1);

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        int disks = n;   

        auto start = chrono::high_resolution_clock::now();
        towerOfHanoi(disks, 'A', 'C', 'B');
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

