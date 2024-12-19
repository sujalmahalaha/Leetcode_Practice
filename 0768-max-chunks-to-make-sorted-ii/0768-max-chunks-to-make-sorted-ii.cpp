class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();
        vector<int> prefixMax(n, INT_MIN);
        vector<int> suffixMin(n, INT_MAX);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            prefixMax[i] = maxi;
        }
        int mini = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, arr[i]);
            suffixMin[i] = mini;
        }
        int chunk = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (prefixMax[i] < suffixMin[i]) {
                    chunk++;
                }
            }
            else{
                if (prefixMax[i-1] <= suffixMin[i]) {
                    chunk++;
                }

            }
        }
        return chunk;
    }
};