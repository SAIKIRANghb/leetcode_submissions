// Last updated: 11/25/2026, 3:42:06 PM
class Solution {
public:
    long long solve(int ind,vector<vector<int>>& questions,vector<long long>&dp){
        int n = questions.size();
        if(ind >= n)return 0;

        if(dp[ind] != -1)return dp[ind];

        long long ans = 0;
        ans = max(solve(ind + 1,questions,dp) , questions[ind][0] +  solve(ind + questions[ind][1] + 1,questions,dp));
        return dp[ind] = ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        // int n = questions.size();
        // vector<long long>dp(n,-1);
        // return solve(0,questions,dp);
        int n = questions.size();

        vector<long long>dp(n + 1,0);

        for(int ind = n - 1;ind >= 0;ind--){
            long long skip = dp[ind + 1];
            long long solve = questions[ind][0] + (ind + questions[ind][1] + 1 < n ? dp[ind + questions[ind][1] + 1] : 0);
            dp[ind] = max(skip,solve);
        }

        return dp[0];
    }
};