#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp_dp(int n, vector<vector<int>>& cost) {
    int VISITED_ALL = 1 << n;
    vector<vector<int>> dp(VISITED_ALL, vector<int>(n, INT_MAX));

    dp[1][0] = 0;

    for (int i = 1; i < VISITED_ALL; i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) != 0) continue;
                int newMask = i | (1 << k);
                dp[newMask][k] = min(dp[newMask][k], dp[i][j] + cost[j][k]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[VISITED_ALL - 1][i] + cost[i][0]);
    }
    return ans;
}

int main() {
    int n = 4;

    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "DP cost: " << tsp_dp(n, cost) << endl;

    return 0;