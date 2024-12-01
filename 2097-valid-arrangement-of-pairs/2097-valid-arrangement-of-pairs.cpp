class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int , vector<int>>adj;
        //Build Indegree and Outdegree
        unordered_map<int, int>indegree , outdegree;
        for(auto it : pairs){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        int StartNode = pairs[0][0];
        //Find the start node for the Euler Path
        for(auto it : adj){
            int node = it.first;
            if((outdegree[node]- indegree[node])==1){
                StartNode = node;
                break;
            }
        }
        vector<int>EulerPath;
        stack<int>st;
        st.push(StartNode);
        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            }
            else{
                EulerPath.push_back(curr);
                st.pop();
            }

        }
        reverse(EulerPath.begin() , EulerPath.end());
        vector<vector<int>>result;
        for(int i = 0 ; i<EulerPath.size()-1 ; i++){
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }
        return result;
        
    }
};