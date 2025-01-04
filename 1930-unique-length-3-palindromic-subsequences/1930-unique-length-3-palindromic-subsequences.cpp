class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        int n = s.size();
        for (auto ch : s) {
            letters.insert(ch);
        }
        int result = 0;
        for (auto letter : letters) {
            int left = -1;
            int right = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (left == -1) {
                        left = i;
                    }
                    right = i;
                }
            }
            unordered_set<char> st;
            for (int middle = left + 1; middle <= right - 1; middle++) {
                st.insert(s[middle]);
            }
            result += st.size();
        }
        return result;
    }
};