// Last updated: 11/25/2026, 3:39:15 PM
class Solution {
public:
    vector<vector<vector<long long>>>dp;
    long long maxCost(int i,int isStart,int sign,vector<int>&nums){
        if(i == nums.size())return 0;
        if(dp[i][isStart][sign] != -1e15) return dp[i][isStart][sign];
        long long ans = -1e15;
        if(isStart == 1){
            ans = max(ans,nums[i] + maxCost(i+1,0,sign^1,nums));
        }else{
            if(sign == 1){
                ans = max(ans, -nums[i] + maxCost(i+1,0,sign^1,nums));
                ans = max(ans,maxCost(i,1,0,nums));
            }else{
                ans = max(ans, nums[i] + maxCost(i+1,0,sign^1,nums));
                ans = max(ans,maxCost(i,1,0,nums));
            }
        }
        return dp[i][isStart][sign] = ans;
    }
    long long maximumTotalCost(vector<int>& nums) {
        dp = vector<vector<vector<long long>>>(nums.size(),vector<vector<long long>>(2,vector<long long>(2,-1e15)));
        return maxCost(0,1,0,nums);
    }
};