class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long  result = 0;
        int i = 0;

        while(i<n){
            long long count = 0;
            while(i<n && nums[i]==0){
                count++;
                i++;
            }
            result += long (count * (count+1))/2;
            i++;



        }
        return result;
        
    }
};