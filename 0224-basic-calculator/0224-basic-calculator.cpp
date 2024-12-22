class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int result = 0;
        int sign = 1;
        int number = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');

            } else if (s[i] == '+') {
                result += number * sign;
                sign = 1;
                number = 0;

            } else if (s[i] == '-') {
                result += number * sign;
                sign = -1;
                number = 0;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;

            } else if (s[i] == ')') {
                result += number * sign;
                number = 0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        result += number * sign;
        return result;
    }
};