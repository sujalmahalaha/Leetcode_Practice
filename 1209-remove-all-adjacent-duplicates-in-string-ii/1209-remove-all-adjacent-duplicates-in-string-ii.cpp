class Solution {
public:
  #define p pair<int,int>
    string removeDuplicates(string s, int k) {
        stack<p>st;
        string ans;
        for(int i = 0 ; i<s.size() ; i++){
            if (!st.empty() && st.top().first == s[i]) {
                // Increment the count for the top character
                st.top().second++;
                // If the count reaches k, pop the character
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                // Push the current character with a count of 1
                st.push({s[i], 1});
            }
        }
         while(!st.empty()){
            while(st.top().second>0){
            ans += st.top().first;
            st.top().second--;
            }
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
};