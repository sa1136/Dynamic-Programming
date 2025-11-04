#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n  = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<long long>> dp(m , vector<long long>(n,0));

        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                        dp[i][j]=0;
                } 
                else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];

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
        cerr << "Then provide " << m << "x" << n << " grid values (0 or 1), one row per line\n";
        return 1;
    }

    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << "\n";
    return 0;
}

