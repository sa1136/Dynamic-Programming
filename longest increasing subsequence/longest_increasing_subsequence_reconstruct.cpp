#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

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

        vector<int> lis;
        int index = 0, prev_index = -1;
        int len = dp[0][0];

        while (index < n) {
            int notTake = dp[index + 1][prev_index + 1];
            int take = 0;
            if (prev_index == -1 || nums[index] > nums[prev_index]) {
                take = 1 + dp[index + 1][index + 1];
            }
            if (dp[index][prev_index + 1] == take && take > notTake) {
                lis.push_back(nums[index]);
                prev_index = index;
            }
            index++;
        }

        cout << "Longest Increasing Subsequence: ";
        for (int num : lis) cout << num << ' ';
        cout << '\n';
        return len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums) << "\n"; // Length printed after LIS line
    return 0;
}
