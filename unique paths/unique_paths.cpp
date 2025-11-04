#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m ,vector<int>(n,1));
        for(int i=1;i<m ;i++){
            for(int j=1;j<n;j++){
                dp[i][j] =dp[i-1][j]+dp[i][j-1];
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
        return 1;
    }

    Solution s;
    cout << s.uniquePaths(m, n) << "\n";
    return 0;
}

