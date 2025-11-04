#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    dp[i] = min(dp[i], jump);
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    vector<int> heights = {10, 5, 20, 0, 15};
    int k = 2;
    cout << s.frogJump(heights, k);
}


