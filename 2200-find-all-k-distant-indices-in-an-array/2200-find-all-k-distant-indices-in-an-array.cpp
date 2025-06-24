class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        set<int>resultset;

        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] == key){
                resultset.insert(i);
                for(int j = i-k && i-k>=0 ; j< nums.size() ; j++){
                    if(abs(i-j)<=k){
                        resultset.insert(j);
                    }
                }
            }
        }
        vector<int>result;
        for(auto i : resultset){
            result.push_back(i);
        }
        sort(result.begin() , result.end());
        return result;
    }
};