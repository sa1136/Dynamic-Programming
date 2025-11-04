#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to compute the minimum path sum using 2D DP
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // Step 1: Create a 2D dp array to store minimum path sums
        // Since it's a triangle, each row has i+1 elements, but we can use n for simplicity
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Step 2: Initialize the last row of dp with the triangle's last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Step 3: Fill dp table from second-last row to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];       // path going straight down
                int diagonal = triangle[i][j] + dp[i + 1][j + 1]; // path going diagonally down-right
                dp[i][j] = min(down, diagonal);
            }
        }

        // Step 4: The top element contains the minimum path sum
        return dp[0][0];
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (argc > 1) {
        n = stoi(argv[1]);
    } else if (cin >> n) {
        // read from stdin
    } else {
        cerr << "Usage: " << argv[0] << " <n>  (or provide n via stdin)\n";
        cerr << "Then provide triangle values: row 1 has 1 value, row 2 has 2 values, etc.\n";
        return 1;
    }

    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    Solution s;
    cout << s.minimumTotal(triangle) << "\n";
    return 0;
}

