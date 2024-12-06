class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(auto it : banned){
            st.insert(it);
        }
        int count = 0;
        long  long sum = 0;
        for(int i = 1 ; i<=n ; i++){
           if(st.find(i) != st.end()){
               continue;
           }
           if(sum + i >maxSum){
             return count;
            //  break;
           }
           sum += i;
           count++;
        }
        return count;
        
    }
};