#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e9; // a large number representing impossible case
        
        // dp[i][t] = minimum coins to make amount 't' using coins[0..i]
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: using only the first coin
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0]; // we can form t using t/coins[0] coins
            else
                dp[0][t] = INF; // impossible to form this amount
        }

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {

                // Not take current coin
                int notTake = dp[i - 1][t];

                // Take current coin (only if it fits)
                int take = INF;
                if (coins[i] <= t)
                    take = 1 + dp[i][t - coins[i]];

                // Choose the better (minimum coins)
                dp[i][t] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][amount];
        return (ans >= INF) ? -1 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << sol.coinChange(coins, amount); // Output: 3
    return 0;
}

