class Solution {
public:

    void Backtracking(int n, string &s, vector<string> &ans) {
    if (s.size() == n) {
        ans.push_back(s);
        return;
    }

    for (char ch : {'a', 'b', 'c'}) {
        if (s.empty() || s.back() != ch) {  // Ensure no adjacent characters are the same
            s.push_back(ch);
            Backtracking(n, s, ans);
            s.pop_back();
        }
    }
}

string getHappyString(int n, int k) {
    vector<string> ans;
    string s = "";
    Backtracking(n, s, ans);
    
    if (ans.size() < k) return "";
    return ans[k - 1]; // Return k-th string (1-based index)
}
};