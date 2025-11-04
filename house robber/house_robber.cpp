#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        // Base cases
        dp[0] = nums[0];
        if (n > 1)
            dp[1] = max(nums[0], nums[1]);

        // ✅ Safe memoization check — dp[n-1], not dp[n]
        if (dp[n - 1] != -1) return dp[n - 1];

        // Fill dp array
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }
};


