#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the maximum number of content students using tabulation
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        int n = student.size();
        int m = cookie.size();

        // Sort both arrays to prepare for DP
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        // Create a 2D DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill DP table from bottom up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                // Skip current cookie
                int skip = dp[i][j + 1];

                // Take current cookie if it satisfies student's greed
                int take = 0;
                if (cookie[j] >= student[i]) {
                    take = 1 + dp[i + 1][j + 1];
                }

                // Take the best of both choices
                dp[i][j] = max(skip, take);
            }
        }

        return dp[0][0];
    }
};

int main() {
    vector<int> student = {1, 2};
    vector<int> cookie = {1, 2, 3};

    // Create Solution object
    Solution solver;

    // Get the number of content students and print it
    int result = solver.findContentChildren(student, cookie);
    cout << "Maximum number of content students: " << result << endl;

    return 0;
}
