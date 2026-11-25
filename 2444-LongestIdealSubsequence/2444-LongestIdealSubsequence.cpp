// Last updated: 11/25/2026, 3:41:42 PM
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int>dp(26,0);
        int ans = 0;
        for(int i = 0;i<n;i++){
            int maxLen = 0;
            for(char prev = 'a';prev<='z';prev++){
                if(abs(s[i] - prev) <= k){
                    maxLen = max(maxLen,1 + dp[prev - 'a']);
                }
            }
            dp[s[i] - 'a'] = maxLen;
            ans = max(ans,maxLen);
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<vector<int>>dp;
    int helper(int i , string s ,int k,char prev){
        int n = s.size();
        if(i == n)return 0;

        if(dp[i][prev -'a'] != -1)return dp[i][prev - 'a'];
        int Pick = 0;
        if(prev =='{'|| abs(prev - s[i]) <= k)Pick = 1 + helper(i + 1,s,k,s[i]);
        int notPick = helper(i + 1,s,k,prev);
        return dp[i][prev - 'a'] = max(Pick,notPick);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        dp = vector<vector<int>>(n,vector<int>(27,-1)); 
        return helper(0,s,k,'{');
    }
};
*/