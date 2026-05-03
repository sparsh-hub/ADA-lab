#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcs(const string& X, const string& Y) {
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;     // characters match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // take best
        }
    }

    // Traceback: reconstruct the actual LCS string
    string lcsStr = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr = X[i - 1] + lcsStr;
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "  LCS String: \"" << lcsStr << "\"\n";

    return dp[m][n];
}

void run_lcs() {
    cout << "\n========== LONGEST COMMON SUBSEQUENCE ==========\n";
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << "  String X: " << X << "\n";
    cout << "  String Y: " << Y << "\n";
    int result = lcs(X, Y);
    cout << "  LCS Length: " << result << endl;
}
