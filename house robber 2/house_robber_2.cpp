#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        vector<int> dp(n, -1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        if (dp[n - 1] != -1) return dp[n - 1];

        for (int i = 2; i < n; i++) {
            int pick = nums[start + i] + dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int case1 = robRange(nums, 0, n - 2);
        int case2 = robRange(nums, 1, n - 1);

        return max(case1, case2);
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) nums.push_back(stoi(argv[i]));
    } else {
        int x;
        while (cin >> x) nums.push_back(x);
    }

    if (nums.empty()) {
        cerr << "Usage: " << argv[0] << " <n1> <n2> ... (or provide via stdin)\n";
        return 1;
    }

    Solution s;
    cout << s.rob(nums) << "\n";
    return 0;
}


