class Solution {
public:
    int n, m;
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0) {
            return 0;
        }

        vis[i][j] = 1; // Mark the current cell as visited
        int sum = grid[i][j];

        // Explore all four directions
        for (auto dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            sum += DFS(grid, vis, new_i, new_j);
        }

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    ans = max(ans, DFS(grid, vis, i, j));
                }
            }
        }

        return ans;
    }
};
