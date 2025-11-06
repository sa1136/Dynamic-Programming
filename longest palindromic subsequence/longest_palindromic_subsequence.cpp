#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // Key insight: Longest Palindromic Subsequence (LPS) can be found
        // by finding the Longest Common Subsequence (LCS) between the string
        // and its reverse. This works because a palindrome reads the same
        // forwards and backwards.
        
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        
        // DP table: dp[i][j] = length of LCS between s[i..n-1] and t[j..n-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill DP table from bottom-up
        // We traverse from the end of both strings to the beginning
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // If characters match, we can include this character in LCS
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                // If characters don't match, take the maximum of:
                // - skipping character from s (dp[i+1][j])
                // - skipping character from t (dp[i][j+1])
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        // The answer is the LCS length between s and its reverse
        // which equals the length of the longest palindromic subsequence
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    cout << "Input: " << s << endl;
    cout << "Longest Palindromic Subsequence length: " << sol.longestPalindromeSubseq(s) << endl; // Output: 4
    return 0;
}

