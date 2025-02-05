class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        vector<int> diff;
        
        // Find positions where characters differ
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        // No swaps needed (already equal)
        if (diff.empty()) {
            return true;
        }

        // Must have exactly 2 differences and be swappable
        if (diff.size() == 2) {
            return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
        }

        return false;  // More than 2 differences mean it can't be swapped
    }
};
