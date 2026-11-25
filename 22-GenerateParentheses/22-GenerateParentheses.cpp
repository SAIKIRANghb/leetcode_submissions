// Last updated: 11/25/2026, 3:50:08 PM
class Solution {
public:
    void solve(int n,int open,int close,string str,vector<string>&ans){
        if(open + close == 2*n && open == close){
            ans.push_back(str);
            return;
        }

        if(open < n){
            solve(n,open + 1,close,str + '(',ans);
        }
        if(close < open){
            solve(n,open,close + 1,str + ')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,0,0,"",ans);
        return ans;
    }
};