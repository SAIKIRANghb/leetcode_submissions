// Last updated: 11/25/2026, 3:38:00 PM
class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        vector<vector<long long>>dp(n + 1,vector<long long>(k + 1,0));
        dp[0][0] = 1;

        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= k;j++){
                dp[i][j] = dp[i - 1][j] % MOD;
                if(j > 0){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1])%MOD;
                }
            }
        }
        long long sumy = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= k;j++){
                sumy = (sumy + nums[i - 1]*dp[i - 1][j - 1] % MOD) % MOD;
                sumy = (sumy + nums[i - 1]*dp[n - i][j - 1] % MOD) % MOD;
            }
        }
        return sumy % MOD;
    }
};