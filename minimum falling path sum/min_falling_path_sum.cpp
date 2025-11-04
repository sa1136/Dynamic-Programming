#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to compute the minimum falling path sum using bottom-up DP
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Create a DP array same size as matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Step 2: Initialize the last row of DP with the matrix's last row (base case)
        for (int col = 0; col < m; col++) {
            dp[n - 1][col] = matrix[n - 1][col];
        }

        // Step 3: Fill DP table from second-last row up to the top
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < m; col++) {
                // Path straight down
                int down = matrix[row][col] + dp[row + 1][col];

                // Path down-left
                int downLeft = 1e9; // initialize with large number
                if (col > 0) {
                    downLeft = matrix[row][col] + dp[row + 1][col - 1];
                }

                // Path down-right
                int downRight = 1e9; // initialize with large number
                if (col < m - 1) {
                    downRight = matrix[row][col] + dp[row + 1][col + 1];
                }

                // Minimum path sum for current cell
                dp[row][col] = min({down, downLeft, downRight});
            }
        }

        // Step 4: Answer is the minimum in the top row
        int minSum = *min_element(dp[0].begin(), dp[0].end());
        return minSum;
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (argc > 2) {
        n = stoi(argv[1]);
        m = stoi(argv[2]);
    } else if (cin >> n >> m) {
        // read from stdin
    } else {
        cerr << "Usage: " << argv[0] << " <n> <m>  (or provide n m via stdin)\n";
        cerr << "Then provide " << n << "x" << m << " matrix values, one row per line\n";
        return 1;
    }

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution s;
    cout << s.minFallingPathSum(matrix) << "\n";
    return 0;
}

