// Last updated: 11/25/2026, 3:47:28 PM
class Solution {
public:
    bool solve(int ind, int sum, vector<int>& nums, vector<vector<bool>>& dp) {
        int n = nums.size();
        
        if (sum == 0) return true;
    
        if (ind == n || sum < 0) return false;
        
        if (dp[ind][sum]) return dp[ind][sum];
        
        bool take = solve(ind + 1, sum - nums[ind], nums, dp);
        
        if (take) return dp[ind][sum] = true;
        
        bool notTake = solve(ind + 1, sum, nums, dp);

        return dp[ind][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int S = accumulate(nums.begin(), nums.end(), 0);

        if (S % 2 != 0) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(S / 2 + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= S / 2; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][S / 2];
    }
};
