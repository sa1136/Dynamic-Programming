#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Problem: Burst Balloons
        // Given balloons with coins, when you burst balloon i, you get
        // nums[left] * nums[i] * nums[right] coins, where left and right
        // are the adjacent balloons. Find maximum coins you can collect.
        
        int n = nums.size();
        // Add boundary balloons with value 1 at both ends
        // This simplifies the problem: we always have valid neighbors
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // DP table: dp[left][right] = maximum coins from bursting all balloons
        // in the open interval (left, right), where left and right are not burst
        // We have n+2 positions now (original n + 1 at start + 1 at end)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // Fill DP table using interval length approach
        // len represents the length of the interval (number of positions between left and right)
        for (int len = 2; len <= n + 1; len++) { // length of interval
            // left is the starting position of the interval
            for (int left = 0; left + len <= n + 1; left++) {
                int right = left + len;  // right is the ending position of the interval
                
                // Try all possible last balloons to burst in this interval
                // k is the last balloon we burst in the interval (left, right)
                // When we burst k last, we get coins from nums[left] * nums[k] * nums[right]
                // because left and right are the boundaries that remain
                for (int k = left + 1; k < right; k++) {
                    // Maximum coins = coins from bursting k last
                    //                 + maximum coins from left part (left, k)
                    //                 + maximum coins from right part (k, right)
                    dp[left][right] = max(dp[left][right],
                        nums[left] * nums[k] * nums[right] +
                        dp[left][k] + dp[k][right]);
                }
            }
        }
        
        // Return maximum coins from bursting all balloons in the interval (0, n+1)
        // which represents all original balloons
        return dp[0][n + 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 5, 8};
    cout << "Balloons: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    cout << "Maximum coins: " << sol.maxCoins(nums) << endl; // Output: 167
    return 0;
}

