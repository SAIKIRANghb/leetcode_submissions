// Last updated: 11/25/2026, 3:44:30 PM
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char> st;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')') {
                // Pop characters from stack until '(' is encountered
                string tempStr = "";
                while (!st.empty() && st.top() != '(') {
                    tempStr += st.top();
                    st.pop();
                }
                // Pop the '('
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                // Push reversed substring back into stack
                for (char c : tempStr) {
                    st.push(c);
                }
            } else {
                // Push non ')' characters onto stack
                st.push(s[i]);
            }
        }
        
        // Build final output string from stack
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
