class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int ps = 0;
        multiset<int>st(begin(workers), begin(workers)+mid);
        for(int i = mid-1 ; i>=0 ; i--){
            int reqd = tasks[i];
            auto it = prev(st.end());
            if(*it>=reqd){
                st.erase(it);
            }else if(ps>=pills){
                return false;
            }
            else{
                auto wit = st.lower_bound(reqd-strength);
                if(wit == st.end()){
                    return false;
                }
                st.erase(wit);
                ps++;
            }
        }
        return true;
    }
       
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();
        int l = 0 ; 
        int r = min(m , n);
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());
        int result = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(tasks , workers , pills , strength , mid)){
                result  = mid ; 
                l  = mid+1;
            }else{
                r = mid-1;
            }
        }
        return result;
    }
};