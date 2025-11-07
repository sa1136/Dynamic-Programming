#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Grid dimensions
    int m, n;

    // Direction vectors: Up, Down, Left, Right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // Check if (x, y) is inside the grid
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited) {
        // Base case: reached destination cell
        if (x == m - 1 && y == n - 1) return true;

        visited[x][y] = 1; // mark current cell as visited

        // Explore all four directions
        for (int k = 0; k < 4; k++) {
            int nx = x, ny = y;

            if (grid[x][y] == 2) {
                // Current cell is ICE: keep sliding until hitting wall or road
                while (isValid(nx + dr[k], ny + dc[k]) && grid[nx + dr[k]][ny + dc[k]] != 1) {
                    nx += dr[k];
                    ny += dc[k];
                    if (grid[nx][ny] == 0) break; // stop sliding when landing on road
                }
            } else {
                // Current cell is ROAD (0) or destination: move one step
                nx += dr[k];
                ny += dc[k];
            }

            // If the new position is valid, not a wall, and not visited yet, continue DFS
            if (isValid(nx, ny) && grid[nx][ny] != 1 && !visited[nx][ny]) {
                if (dfs(grid, nx, ny, visited)) return true;
            }
        }

        return false; // no path found from this cell
    }

    bool canReach(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (grid[0][0] == 1) return false; // start is a wall

        vector<vector<int>> visited(m, vector<int>(n, 0));
        return dfs(grid, 0, 0, visited);
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid1 = {{0, 0}, {1, 0}};
    cout << (s.canReach(grid1) ? "TRUE" : "FALSE") << '\n';

    vector<vector<int>> grid2 = {{0, 1}, {1, 0}};
    cout << (s.canReach(grid2) ? "TRUE" : "FALSE") << '\n';

    vector<vector<int>> grid3 = {{0, 2, 2, 2}, {1, 1, 0, 1}, {0, 0, 0, 0}};
    cout << (s.canReach(grid3) ? "TRUE" : "FALSE") << '\n';

    vector<vector<int>> grid4 = {{2, 2, 2}, {2, 2, 2}};
    cout << (s.canReach(grid4) ? "TRUE" : "FALSE") << '\n';

    return 0;
}
