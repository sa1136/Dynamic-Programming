#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];

        }
        return dp[n];
        
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
        return 1;
    }

    Solution s;
    cout << s.climbStairs(n) << "\n";
    return 0;
}

