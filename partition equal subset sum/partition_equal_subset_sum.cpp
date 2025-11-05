#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Determines if the given array can be split into two subsets
    // whose sums are equal using a tabulation DP approach
    bool canPartition(int n, vector<int>& arr) {
        // Step 1: Calculate the total sum
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        // Step 2: If total sum is odd, partition is impossible
        if (totalSum % 2 != 0) {
            return false;
        }

        // Step 3: Determine the target sum for each subset
        int targetSum = totalSum / 2;

        // Step 4: Create DP table and initialize
        vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false));

        // Step 5: Base case: sum 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Step 6: Initialize first row
        if (arr[0] <= targetSum) {
            dp[0][arr[0]] = true;
        }

        // Step 7: Fill DP table
        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= targetSum; target++) {
                bool notTaken = dp[index - 1][target];
                bool taken = false;
                if (arr[index] <= target) {
                    taken = dp[index - 1][target - arr[index]];
                }
                dp[index][target] = notTaken || taken;
            }
        }

        // Step 8: Return result
        return dp[n - 1][targetSum];
    }
};

int main() {
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = (int)arr.size();
    Solution solver;

    if (solver.canPartition(n, arr)) {
        cout << "The array can be partitioned into two equal subsets";
    } else {
        cout << "The array cannot be partitioned into two equal subsets";
    }
    return 0;
}
