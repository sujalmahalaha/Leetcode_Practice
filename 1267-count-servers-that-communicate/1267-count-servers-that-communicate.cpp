class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowCount(n, 0), colCount(m, 0);
        int totalServers = 0;

        // Count servers in each row and column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                    totalServers++;
                }
            }
        }

        int nonCommunicating = 0;

        // Check for non-communicating servers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    nonCommunicating++;
                }
            }
        }

        // Total communicating servers = total servers - isolated servers
        return totalServers - nonCommunicating;
    }
};
