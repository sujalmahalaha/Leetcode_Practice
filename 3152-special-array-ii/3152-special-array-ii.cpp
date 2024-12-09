class Solution {
public:
    // pair<int , int>p;
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> store(n, 0);
        for (int i = 1; i < n ; i++) {
            if (nums[i] % 2 != nums[i -1] % 2) {
                store[i] += store[i-1];
            } else {
                store[i] = store[i-1] +1;
            }
        }

        vector<bool> result;
        for (auto it : queries) {
            int start = it[0];
            int end = it[1];
           if(store[end]-store[start] == 0){
            result.push_back(true);
           }
           else{
            result.push_back(false);
           }
        }
        return result;
    }
};