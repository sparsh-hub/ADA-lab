#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void sumOfSubsetUtil(vector<int>& set, vector<int>& subset,
                     int index, int current, int target, int n,
                     int& count) {
    if (current == target) {
        count++;
        cout << "  Subset " << count << ": { ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
        return;
    }

    for (int i = index; i < n; i++) {
        // Pruning: only proceed if adding set[i] doesn't exceed target
        if (current + set[i] <= target) {
            subset.push_back(set[i]);
            sumOfSubsetUtil(set, subset, i + 1, current + set[i],
                            target, n, count);
            subset.pop_back(); // Backtrack
        }
    }
}

void sumOfSubset(vector<int>& set, int target) {
    sort(set.begin(), set.end()); // Sort for better pruning
    vector<int> subset;
    int count = 0;
    sumOfSubsetUtil(set, subset, 0, 0, target, set.size(), count);
    if (count == 0)
        cout << "  No subset found with sum = " << target << "\n";
    else
        cout << "  Total subsets found: " << count << endl;
}

void run_sum_of_subset() {
    cout << "\n========== SUM OF SUBSETS ==========\n";
    vector<int> set = {3, 1, 2, 5, 4, 9};
    int target = 9;
    cout << "  Set: {3, 1, 2, 5, 4, 9}\n";
    cout << "  Target Sum: " << target << "\n";
    sumOfSubset(set, target);
}