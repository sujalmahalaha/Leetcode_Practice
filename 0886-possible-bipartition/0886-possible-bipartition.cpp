class Solution {
public:
    bool BFS(unordered_map<int, vector<int>>& adj, int node,
             vector<int>& color) {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it : adj[curr]) {

                if (color[it] == color[curr]) {
                    return false;
                }

                if (color[it] == -1) {
                    color[it] = !(color[curr]);
                    q.push(it);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;

        for (auto it : dislikes) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (BFS(adj, i, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};