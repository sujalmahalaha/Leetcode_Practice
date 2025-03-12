class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int cn = 0;
        int cp = 0;
        for(int i = 0 ; i< n ; i++){
            if(nums[i]>0){
                cp++;
            }
            if(nums[i]<0){
                cn++;
            }
        }
        return max(cp , cn);
        
    }
};