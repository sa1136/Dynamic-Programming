#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: dp[n][0] = dp[n][1] = 0  (no days left → no profit)

        for (int i = n - 1; i >= 0; i--) {
            // When we are allowed to buy
            int take = -prices[i] + dp[i + 1][0];  // buy
            int notTake = dp[i + 1][1];            // skip
            dp[i][1] = max(take, notTake);

            // When we are allowed to sell
            take = prices[i] + dp[i + 1][1];       // sell
            notTake = dp[i + 1][0];                // skip
            dp[i][0] = max(take, notTake);
        }

        return dp[0][1]; // start from day 0, we are allowed to buy
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl; // Output: 7
    return 0;
}

