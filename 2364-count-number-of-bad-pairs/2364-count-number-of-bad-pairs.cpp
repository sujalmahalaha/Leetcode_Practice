class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            nums[i] = nums[i]-i;
        }
        unordered_map<int , int>mp;
        mp[nums[0]]= 1;
        for(int i = 1 ; i< nums.size() ; i++){
            result += i-mp[nums[i]];
            mp[nums[i]]++;
        }
        return result;

        
    }
};