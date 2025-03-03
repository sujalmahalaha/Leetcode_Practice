class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans;
        int count =0;
        for(auto it : nums){
            if(it<pivot){
                ans.push_back(it);
            }
            if(it==pivot){
                count++;
            }
        }
        while(count>0){
            ans.push_back(pivot);
            count--;
        }
         for(auto it : nums){
            if(it>pivot){
                ans.push_back(it);
            }
        }
        return ans;
        
    }
};