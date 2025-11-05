#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If (S + target) is odd or negative, impossible to partition
        if ((totalSum + target) % 2 != 0 || totalSum < abs(target))
            return 0;

        int S1 = (totalSum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(S1 + 1, 0));

        // Base case
        if (nums[0] == 0)
            dp[0][0] = 2;  // +0 and -0
        else
            dp[0][0] = 1;  // Not take

        if (nums[0] != 0 && nums[0] <= S1)
            dp[0][nums[0]] = 1;  // Take it

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= S1; sum++) {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (nums[i] <= sum)
                    take = dp[i - 1][sum - nums[i]];
                dp[i][sum] = take + notTake;
            }
        }

        return dp[n - 1][S1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}

