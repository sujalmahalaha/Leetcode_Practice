class Solution {
public:
   string removeStars(string s) {
    stack<char> st;

    // Traverse the string
    for (char ch : s) {
        if (ch == '*') {
            if (!st.empty()) st.pop();  // Remove the last valid character
        } else {
            st.push(ch);  // Push valid characters
        }
    }

    // Construct the resulting string from the stack
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Reverse the string to maintain the original order
    reverse(ans.begin(), ans.end());
    return ans;
}
};