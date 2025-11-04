#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = (int)heights.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int first = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int second = INT_MAX;
            if (i > 1) {
                second = dp[i - 2] + abs(heights[i] - heights[i - 2]);
            }
            dp[i] = min(first, second);
        }
        return dp[n - 1];
    }
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> heights;
    // Prefer command-line args; else read from stdin
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            heights.push_back(stoi(argv[i]));
        }
    } else {
        int x;
        while (cin >> x) heights.push_back(x);
    }

    if (heights.empty()) {
        cerr << "Usage: " << argv[0] << " <h1> <h2> ... (or provide space-separated heights via stdin)\n";
        return 1;
    }

    Solution s;
    cout << s.frogJump(heights) << "\n";
    return 0;
}


