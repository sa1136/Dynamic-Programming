#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size();
        int n= grid[0].size();

        vector<vector<int>> dp(m , vector<int>(n,0));

        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(i==0 && j==0) {
                    dp[i][j]=grid[0][0];
                }
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0) up = grid[i][j]+ dp[i-1][j];
                    if(j>0) left = grid[i][j]+dp[i][j-1];

                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (argc > 2) {
        m = stoi(argv[1]);
        n = stoi(argv[2]);
    } else if (cin >> m >> n) {
        // read from stdin
    } else {
        cerr << "Usage: " << argv[0] << " <m> <n>  (or provide m n via stdin)\n";
        cerr << "Then provide " << m << "x" << n << " grid values, one row per line\n";
        return 1;
    }

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution s;
    cout << s.minPathSum(grid) << "\n";
    return 0;
}

