#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ctime>

void generateBinaryTruthTable(int n, string &current,int index, vector<string> &result) {
    if(index == n) {
        result.push_back(current);
        return;
    }
    current[index] = 'F';
    generateBinaryTruthTable(n, current, index + 1, result);
    current[index] = 'T';
    generateBinaryTruthTable(n, current, index + 1, result);
}

int main() {
    int n;
    int t;
    cin >> n;
    t = n;
    
    ofstream file("timings.csv");
    file << "n,time\n";
    vector<int> durationArray(n);
    cout << "value of n     -> " << "     time taken" << endl;
    while(n>0){
        auto start = chrono::high_resolution_clock::now();

        vector<string> result;
        string current(10, 'F');
        generateBinaryTruthTable(10, current, 0, result);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        durationArray[n] = duration.count();
        cout << "     " << n << "         ->      " << duration.count() << " nanoseconds" << endl;
        file << n << "," << duration.count() << "\n";
        n--;
    }
    int sum = 0;
    for(auto time: durationArray){
        sum += time;
    }
    int avg = sum/(t);
    cout <<"the average time taken to execute the program is " << avg;
    file.close();
    return 0;
}