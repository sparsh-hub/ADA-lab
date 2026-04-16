#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

void generatePermutations(string &chars, int start, vector<string> &result) {
    if (start >= chars.size()) {
        result.push_back(chars);
        return;
    }
    for (int i = start; i < chars.size(); i++) {
        swap(chars[start], chars[i]);
        generatePermutations(chars, start + 1, result);
        swap(chars[start], chars[i]);
    }
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;

    vector<int> durationArray(n + 1);

    cout << "value of n     ->     time taken" << endl;

    while (n > 0) {
        string chars;
        for (int i = 0; i < n; i++) {
            chars.push_back('A' + i);
        }

        vector<string> result;

        auto start = chrono::high_resolution_clock::now();
        generatePermutations(chars, 0, result);
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
