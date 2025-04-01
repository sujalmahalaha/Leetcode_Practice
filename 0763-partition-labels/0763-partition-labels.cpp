class Solution {
public:
   vector<int> partitionLabels(string s) {
    vector<int> ans;
    vector<int> last(26, 0);

    // Record the last occurrence of each character
    for (int i = 0; i < s.size(); i++) {
        last[s[i] - 'a'] = i;
    }

    int start = 0, end = 0;

    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i] - 'a']);  // Update the current partition end
        // If we reach the end of the current partition
        if (i == end) {
            ans.push_back(end - start + 1);  // Length of current partition
            start = i + 1;  // Move to the next partition
        }
    }
    return ans;
}
};