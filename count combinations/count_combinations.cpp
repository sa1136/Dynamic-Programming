#include <iostream>
#include <vector>
using namespace std;

int countCombinations(vector<int>& nums, int target, int num_coins) {
    int n = nums.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(num_coins + 1, vector<int>(target + 1, 0)));

    // Base case: using only the first coin
    for (int k = 0; k <= num_coins; k++) {
        for (int t = 0; t <= target; t++) {
            if (k == 0 && t == 0) dp[0][k][t] = 1;          // zero coins to make sum 0
            else if (k == 1 && t == nums[0]) dp[0][k][t] = 1; // take first coin
            else dp[0][k][t] = 0;
        }
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int k = 0; k <= num_coins; k++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[i-1][k][t];
                int take = 0;
                if (k > 0 && nums[i] <= t)
                    take = dp[i-1][k-1][t - nums[i]];
                dp[i][k][t] = take + notTake;
            }
        }
    }

    return dp[n-1][num_coins][target];
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 7;
    int num_coins = 2;
    cout << countCombinations(nums, target, num_coins) << endl; // Output: 2
    return 0;
}

