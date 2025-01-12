class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 == 1)return false;
        stack<int>Open;
        stack<int>OpenClose;
        for(int i = 0 ; i<n ;i++){
            if(s[i]=='('){
                if(locked[i] == '1'){
                Open.push(i);
                }
                else{
                    OpenClose.push(i);
                }
            }
            else{
                if(locked[i] == '0'){
                 OpenClose.push(i);
                }
                else if(!Open.empty()){
                    Open.pop();
                }
                else if(!OpenClose.empty()){
                    OpenClose.pop();
                }
                else{
                    return false;
                }


            }
        }
        while(!Open.empty() && !OpenClose.empty() && Open.top()<OpenClose.top()){
             Open.top();
             OpenClose.top();
        }
        return Open.empty();
        
    }
};