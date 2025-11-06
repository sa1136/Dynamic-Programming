#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        // Reconstruct LCS
        string lcs = "";
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (text1[i] == text2[j]) {
                lcs.push_back(text1[i]);
                i++; j++;
            } 
            else if (dp[i + 1][j] > dp[i][j + 1])
                i++;
            else
                j++;
        }

        cout << "Longest Common Subsequence: " << lcs << "\n";
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    string a = "abcde";
    string b = "ace";
    cout << sol.longestCommonSubsequence(a, b) << "\n"; // Output length
    return 0;
}
