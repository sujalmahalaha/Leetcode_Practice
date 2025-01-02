class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> count(words.size(), 0);
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int result = 0;

        // Compute prefix sum array
        for (int i = 0; i < words.size(); i++) {
            int n = words[i].size();
            if (st.find(words[i][0]) != st.end() &&
                st.find(words[i][n - 1]) != st.end()) {
                result++;
            }
            count[i] = result;
        }

        // Process each query
        for (auto& it : queries) {
            int u = it[0];
            int v = it[1];
            if (u == 0) {
                ans.push_back(count[v]);
            } else {
                ans.push_back(count[v] - count[u - 1]);
            }
        }

        return ans;
    }
};
