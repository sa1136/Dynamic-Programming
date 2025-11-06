#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Key insight: To find minimum deletions to make two strings equal,
        // we need to find the Longest Common Subsequence (LCS).
        // Minimum deletions = total length of both strings - 2 * LCS length
        // This is because we keep the LCS and delete everything else
        
        int n1 = word1.size(), n2 = word2.size();
        // DP table: dp[i][j] = length of LCS between word1[i..n1-1] and word2[j..n2-1]
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill DP table from bottom-right to top-left
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                // If characters match, include in subsequence
                if (word1[i] == word2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                // If characters don't match, take maximum of skipping either character
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        int lcsLength = dp[0][0];  // length of Longest Common Subsequence
        return n1 + n2 - 2 * lcsLength;  // minimum deletions needed
    }
};

int main() {
    Solution sol;
    string word1 = "sea";
    string word2 = "eat";
    cout << "word1: " << word1 << ", word2: " << word2 << endl;
    cout << "Minimum deletions: " << sol.minDistance(word1, word2) << endl; // Output: 2
    return 0;
}

