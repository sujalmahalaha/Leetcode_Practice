class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int result = 0;
       int j = 1;
       int i = 0;
       while(j+1<nums.size()){
        if((nums[i]<nums[j] && nums[j]>nums[j+1])||(nums[i]>nums[j]&&nums[j]<nums[j+1])){
            result++;
            i=j;
        }
        j++;
       }
        return result;
    }
};