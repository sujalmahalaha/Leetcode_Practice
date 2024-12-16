class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<long long> result(nums.begin(), nums.end()); // Use long long internally
        int l = 0;

        while (l < k) {
            long long mini = LLONG_MAX;
            int index = 0;

            for (int i = 0; i < result.size(); i++) {
                if (result[i] < mini) {
                    mini = result[i];
                    index = i;
                }
            }

            result[index] = result[index] * multiplier;
            l++;
        }

        // Convert back to vector<int> before returning
        vector<int> finalResult(result.begin(), result.end());
        return finalResult;
    }
};
