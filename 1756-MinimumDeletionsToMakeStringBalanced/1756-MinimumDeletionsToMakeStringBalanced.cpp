// Last updated: 11/25/2026, 3:43:22 PM
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int n = s.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == 'a'){
                while(!st.empty() && i<n && s[i] == 'a'){
                    st.pop();
                    count++;
                    i++;
                }
            }
            if(s[i] == 'b')st.push(s[i]);
        }
        return count;
    }
};