#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Don't pick item i
            dp[i][w] = dp[i - 1][w];

            // Pick item i (only if it fits)
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i][w],
                               dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    // Traceback: find which items were selected
    cout << "  Items selected: ";
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item" << i << "(w=" << weights[i-1] << ",v=" << values[i-1] << ") ";
            w -= weights[i - 1];
        }
    }
    cout << endl;

    return dp[n][W];
}

void run_knapsack() {
    cout << "\n========== 0/1 KNAPSACK ==========\n";
    int W = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values  = {60, 100, 120};
    int n = weights.size();

    cout << "  Capacity: " << W << "\n";
    cout << "  Weights:  {10, 20, 30}\n";
    cout << "  Values:   {60, 100, 120}\n";
    int result = knapsack(W, weights, values, n);
    cout << "  Max Value: " << result << endl;
}