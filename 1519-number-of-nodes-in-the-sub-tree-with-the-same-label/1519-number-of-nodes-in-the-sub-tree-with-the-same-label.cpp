class Solution {
public:
    void DFS(unordered_map<int , vector<int>>&adj , int curr , int parent , string &labels , vector<int>&result , vector<int>&count){
        char MyLabels = labels[curr];
        int before = count[MyLabels-'a'];
        count[MyLabels-'a' ] += 1;
        for(int &v : adj[curr]){
            if(v == parent){
                continue;
            }
            DFS(adj , v , curr , labels , result , count);
        }
        int after = count[MyLabels-'a'];
        result[curr] = after-before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int , vector<int>>adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(n , 0);
        vector<int>count(26, 0);
        DFS(adj , 0 , -1 , labels , result , count);
        return result;
        
    }
};