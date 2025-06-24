class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        set<int>resultset;

        for(int i = 0 ; i< nums.size() ; i++){
            if(nums[i] == key){
                resultset.insert(i);
                if(i-k >= 0 && i+k <= nums.size()){
                    for(int j = i-k && j>=0 ; j<=i+k && j<nums.size() ; j++){
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