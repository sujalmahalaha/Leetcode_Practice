class Solution {
public:
    bool DFS(unordered_map<int , vector<int>>&adj , vector<int>&vis , int s , int T){
        vis[s] = 1;
        for(auto v : adj[s]){
            if(!vis[v]){
                if(v == T ){
                    return true;
                }
                if(DFS(adj , vis , v , T)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& p, vector<vector<int>>& queries) {
        unordered_map<int , vector<int>>adj;
        for(auto it : p){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        int n = queries.size();
        vector<bool>result(n ,false);
        for(int it = 0 ; it<n ; it++){
            int source = queries[it][0];
            int target = queries[it][1];
            vector<int>vis(numCourses,0);
            result[it] = DFS(adj , vis , source , target);
        }
        return result;
    }
};