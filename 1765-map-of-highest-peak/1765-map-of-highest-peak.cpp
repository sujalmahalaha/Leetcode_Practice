class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& s) {
        int n = s.size();
        int m = s[0].size();
        vector<vector<int>> grid(n, vector<int>(m, -1)); // Initialize all cells to -1
        queue<pair<int, int>> pq; // Queue for BFS

        // Initialize the queue with all water cells and set them to height 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 1) {
                    grid[i][j] = 0;
                    pq.push({i, j});
                }
            }
        }

        // Directions for moving up, down, left, and right
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Perform BFS
        while (!pq.empty()) {
            auto [i, j] = pq.front(); // Retrieve the front element
            pq.pop(); // Pop the element

            for (auto dir : direction) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                // Check bounds and unvisited condition
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] == -1) {
                    grid[i_][j_] = grid[i][j] + 1; // Update height
                    pq.push({i_, j_}); // Push to queue
                }
            }
        }

        return grid;
    }
};
