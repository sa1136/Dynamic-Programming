#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        // Key insight: To make a string palindrome with minimum insertions,
        // we need to find the Longest Palindromic Subsequence (LPS).
        // The minimum insertions = total length - LPS length
        // This is because we can keep the LPS and insert the remaining characters
        
        string t = s;
        reverse(t.begin(), t.end());  // reverse string
        int n = s.size();

        // DP table: dp[i][j] = length of LCS between s[i..n-1] and t[j..n-1]
        // Since t is the reverse of s, this gives us the LPS length
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill DP table from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // If characters match, include in subsequence
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                // If characters don't match, take maximum of skipping either character
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        int lpsLength = dp[0][0];  // length of Longest Palindromic Subsequence
        return n - lpsLength;      // minimum insertions needed
    }
};

int main() {
    Solution sol;
    string s = "mbadm";
    cout << "Input: " << s << endl;
    cout << "Minimum insertions to make palindrome: " << sol.minInsertions(s) << endl; // Output: 2
    return 0;
}

