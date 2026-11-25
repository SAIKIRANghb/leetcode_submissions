// Last updated: 11/25/2026, 3:39:05 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(2,vector<int>(2,0));
        for(int i = 0;i<n;i++){
            int mod = nums[i]%2;
            dp[mod][0] = max(dp[mod][0],dp[0][mod] + 1);
            dp[mod][1] = max(dp[mod][1],dp[1][mod] + 1);
        }
        return max({dp[0][0],dp[0][1],dp[1][0],dp[1][1]});
    }
};