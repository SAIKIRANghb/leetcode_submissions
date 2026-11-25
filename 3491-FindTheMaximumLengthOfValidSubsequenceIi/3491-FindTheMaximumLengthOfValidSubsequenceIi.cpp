// Last updated: 11/25/2026, 3:39:03 PM
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(k,0));
        int maxi = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int curRem = nums[i] % k;
            for(int prevRem = 0 ;prevRem < k ;prevRem++){
                dp[curRem][prevRem] = max(dp[curRem][prevRem] , dp[prevRem][curRem] + 1);
                maxi = max(maxi,dp[curRem][prevRem]);
            }
        }
        return maxi;
    }
};