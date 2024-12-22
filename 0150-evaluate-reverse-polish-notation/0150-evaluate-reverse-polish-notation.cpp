class Solution {
public:
    int evalRPN(vector<string>& t) {
        
        int n = t.size();
        stack<int>st;
        for(int i = 0 ; i<n ; i++){
            if(t[i]=="+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first+second);

            }
            else if(t[i] == "-"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second-first);


            }
            else if(t[i] =="*"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second*first);

            }
            else if(t[i] == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second/first);

            }
            else{
                st.push(stoi(t[i]));
            }
            
        }
        return st.top();
    }
};