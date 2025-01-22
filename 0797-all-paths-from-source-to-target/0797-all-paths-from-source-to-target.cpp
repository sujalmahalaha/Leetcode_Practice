class Solution {
public:
    void dfs(vector<vector<int>>&graph , int u , int target , vector<vector<int>>&result , vector<int>&temp){
        temp.push_back(u);
        if(u == target){
            result.push_back(temp);
        }
        else{
            for(int v : graph[u]){
                dfs(graph , v , target , result , temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>>result;
        vector<int>temp;
        int s = 0;
        int t = n-1;
        dfs(graph , s , t , result , temp);
        return result ;
    }
};