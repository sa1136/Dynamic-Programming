#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // Use unsigned long long to avoid overflow
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        // Base case: using only the first coin
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) dp[0][t] = 1; // Can form t using coins[0] only
        }

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                // Not take current coin
                unsigned long long notTake = dp[i - 1][t];

                // Take current coin (if possible)
                unsigned long long take = 0;
                if (coins[i] <= t)
                    take = dp[i][t - coins[i]];

                dp[i][t] = take + notTake;
            }
        }

        // Return answer as int (problem guarantees it fits)
        return (int)dp[n - 1][amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << sol.change(amount, coins) << endl; // Output: 4
    return 0;
}

