#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to find the minimum number of operations for matrix multiplication
int matrixMultiplication(vector<int>& arr, int N) {
    // arr[i] represents the dimensions of matrix i: arr[i-1] x arr[i]
    // For N matrices, we have N+1 dimensions in the array
    // Example: arr = [10, 20, 30, 40, 50] means:
    // Matrix 1: 10x20, Matrix 2: 20x30, Matrix 3: 30x40, Matrix 4: 40x50
    
    // Create a DP table to store the minimum number of operations
    // dp[i][j] = minimum operations to multiply matrices from i to j
    vector<vector<int>> dp(N, vector<int>(N, -1));

    // Initialize the diagonal elements of the DP table to 0
    // A single matrix requires no multiplication operations
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    // Loop for the length of the chain (number of matrices in the subproblem)
    for (int len = 2; len < N; len++) {
        // i is the starting index of the chain
        for (int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;  // j is the ending index of the chain
            dp[i][j] = INT_MAX;

            // Try different partition points k to find the minimum cost
            // We can split the chain at any point k between i and j-1
            for (int k = i; k < j; k++) {
                // Cost = cost of left part + cost of right part + cost of multiplying them
                // arr[i-1] * arr[k] * arr[j] is the cost of multiplying the two resulting matrices
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // The result is stored in dp[1][N-1]
    // This represents the minimum operations to multiply all matrices from 1 to N-1
    return dp[1][N - 1];
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

    cout << "The minimum number of operations for matrix multiplication is " 
         << matrixMultiplication(arr, n) << endl;

    return 0;
}

