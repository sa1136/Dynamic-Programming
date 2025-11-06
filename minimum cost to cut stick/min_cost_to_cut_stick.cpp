#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // Problem: Given a stick of length n and cut positions in cuts[],
        // find the minimum cost to cut the stick at all given positions.
        // Cost of cutting = length of the stick being cut
        
        int m = cuts.size();
        // Add boundary cuts (0 and n) to make the problem easier
        // This allows us to work with segments between cuts
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());  // Sort cuts to process in order

        // DP table: dp[i][j] = minimum cost to cut the stick segment from cuts[i] to cuts[j]
        // We have m+2 positions now (original m cuts + 0 + n)
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        // Fill DP table using length-based approach (similar to matrix chain multiplication)
        // len represents the number of segments between positions i and j
        for (int len = 2; len <= m + 1; len++) {
            // i is the starting position index
            for (int i = 0; i + len <= m + 1; i++) {
                int j = i + len;  // j is the ending position index
                dp[i][j] = INT_MAX;
                
                // Try all possible cut positions k between i and j
                // We can cut at any position k between i+1 and j-1
                for (int k = i + 1; k < j; k++) {
                    // Cost = length of current segment (cuts[j] - cuts[i])
                    //        + cost of cutting left part (dp[i][k])
                    //        + cost of cutting right part (dp[k][j])
                    dp[i][j] = min(dp[i][j], 
                                   (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j]);
                }
                // If no valid cut found (shouldn't happen with len >= 2), set to 0
                if (dp[i][j] == INT_MAX) dp[i][j] = 0;
            }
        }
        
        // Return minimum cost to cut the entire stick (from position 0 to position m+1)
        return dp[0][m + 1];
    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << "Stick length: " << n << ", Cut positions: ";
    for (int cut : cuts) cout << cut << " ";
    cout << endl;
    cout << "Minimum cost to cut stick: " << sol.minCost(n, cuts) << endl; // Output: 16
    return 0;
}

