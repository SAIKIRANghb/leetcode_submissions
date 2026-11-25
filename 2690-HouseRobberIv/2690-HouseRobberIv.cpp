// Last updated: 11/25/2026, 3:40:59 PM
// class Solution {
// public:
//     int solve(int ind,vector<int>&nums,int k,vector<vector<int>>&dp){
//         if(k == 0)return 0;
//         if(ind >= nums.size())return INT_MAX;
//         if(dp[ind][k] != -1)return dp[ind][k];
//         int take = max(nums[ind],solve(ind + 2,nums,k - 1,dp));
//         int notTake = solve(ind + 1,nums,k,dp);
//         return dp[ind][k] = min(take,notTake);
//     }
//     int minCapability(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<vector<int>>dp(n + 1,vector<int>(k + 1,-1));
//         return solve(0,nums,k,dp);
//     }
// };


class Solution {
public:
    bool canRobKHouses(vector<int>&nums,int mid,int k){
        int n = nums.size();
        int robbed = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] <= mid){
                robbed++;
                i++;     //must be done because we need only non adjacent
            }
            if(robbed >= k)return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1 , r = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canRobKHouses(nums,mid,k)){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};