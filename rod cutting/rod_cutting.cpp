#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(vector<int>& price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Base case: first piece of length 1
    for (int len = 0; len <= n; len++) {
        dp[0][len] = len * price[0]; // can only take length 1 multiple times
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        int rodLength = i + 1;
        for (int len = 0; len <= n; len++) {
            int notTake = dp[i - 1][len];
            int take = 0;
            if (rodLength <= len)
                take = price[i] + dp[i][len - rodLength];
            dp[i][len] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

int main() {
    vector<int> price = {2, 5, 7, 8, 10}; // price of lengths 1, 2, 3, 4, 5
    int n = price.size();
    cout << "Maximum profit: " << rodCutting(price, n) << endl;
    return 0;
}

