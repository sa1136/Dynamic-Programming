#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Bottom-up: from last index to 0
        for (int index = n - 1; index >= 0; index--) {
            for (int prev_index = index - 1; prev_index >= -1; prev_index--) {
                
                int notTake = dp[index + 1][prev_index + 1];
                int take = 0;
                
                if (prev_index == -1 || nums[index] > nums[prev_index]) {
                    take = 1 + dp[index + 1][index + 1];
                }
                
                dp[index][prev_index + 1] = max(take, notTake);
            }
        }
        
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums) << endl; // Output: 4
    return 0;
}

