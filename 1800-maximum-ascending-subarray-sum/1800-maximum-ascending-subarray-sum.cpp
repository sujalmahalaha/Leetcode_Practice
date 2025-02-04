class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int i = 0 ; 
        int j = 0;
        while(i<nums.size()){
            int total = nums[i];
            j = i+1;
            while(j<nums.size()&&nums[j]>nums[j-1]){
                total += nums[j];
                j++;
            }
            sum = max(sum , total);
           i++;

        }
        return sum ;
        
    }
};