class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int LongestIncreasing = 1;
        int LongestDecreasing = 1;
        
        int i = 0;
        while (i < nums.size()) {
            // Count the length of strictly increasing subarray
            int j = i + 1;
            while (j < nums.size() && nums[j] > nums[j - 1]) {
                ++j;
            }
            LongestIncreasing = max(LongestIncreasing, j - i);

            if (i == j - 1) ++i;
            else i = j;
        }
         
        i = 0; // Reset i for the decreasing subarray
        
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size() && nums[j] < nums[j - 1]) {
                ++j;
            }
            LongestDecreasing = max(LongestDecreasing, j - i); // Update LongestDecreasing after counting the length of the decreasing subarray

            if (i == j - 1) ++i;
            else i = j;
        }
        
        return max(LongestIncreasing, LongestDecreasing);
    }
};
