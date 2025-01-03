class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int , vector<int>>adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n , false);
        queue<int>q;
        q.push(source);
        vis[source] =true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination)return true;
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        return false;
        
    }
};