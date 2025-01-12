class Solution {
public:
    bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n % 2 == 1) return false; // A valid string must have an even length

    stack<int> Open;       // Tracks locked '('
    stack<int> OpenClose;  // Tracks unlocked '(' or ')'

    // First pass: process the string
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (locked[i] == '1') {
                Open.push(i); // Push locked '('
            } else {
                OpenClose.push(i); // Push unlocked '('
            }
        } else { // s[i] == ')'
            if (locked[i] == '0') {
                OpenClose.push(i); // Push unlocked ')'
            } else if (!Open.empty()) {
                Open.pop(); // Use a locked '(' to balance
            } else if (!OpenClose.empty()) {
                OpenClose.pop(); // Use an unlocked '(' or ')'
            } else {
                return false; // No valid '(' to balance ')'
            }
        }
    }

    // Cleanup phase: match remaining '(' and ')' in Open and OpenClose
    while (!Open.empty() && !OpenClose.empty() && Open.top() < OpenClose.top()) {
        Open.pop();
        OpenClose.pop();
    }

    // If no unmatched locked '(' remain, the string can be valid
    return Open.empty();
}

};