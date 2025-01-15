class Solution {
public:
    long root_result = 0;
    int N ;
    vector<int>count;
     int dfsBase(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        
        root_result += curr_depth;
        
        for(int &child : adj[curr_node]) {
            if(child == prev_node)
                continue;
            
            total_node += dfsBase(adj, child, curr_node, curr_depth+1);
        }
        
        //store count of subtrees of each node
        count[curr_node] = total_node;
        
        return total_node;
    }
    void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int>&result){
      for(auto child : adj[parent_node]){
        if(child==prev_node){
            continue;
        }
        result[child] = result[parent_node]-count[child]+(N-count[child]);
        DFS(adj , child , parent_node , result);
      }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>>adj;
        N = n;
          count.resize(n,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfsBase(adj , 0 , -1 , 0);
        vector<int>result(n , 0);
        result[0] = root_result;
        DFS(adj , 0 , -1 , result);
        return result;
        
    }
};