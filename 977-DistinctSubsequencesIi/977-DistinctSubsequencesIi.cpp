// Last updated: 11/25/2026, 3:45:34 PM
class Solution {
public:
    int M=1e9+7;
    int t[2002];
    int solve(string&s,int i){
        if(i>=s.size()) return 0;
        if(t[i]!=-1) return t[i];
        int take=0;
        unordered_set<char>st;
        for(int j=i;j<s.size();j++){
            if(st.count(s[j])) continue;
            take=(take+1+solve(s,j+1)%M)%M;
            st.insert(s[j]);
        }
        return t[i]=take;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        int ans=0;
        memset(t,-1,sizeof(t));
        unordered_set<char>st;
        return solve(s,0);
    }
};