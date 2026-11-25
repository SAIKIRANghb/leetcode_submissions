// Last updated: 11/25/2026, 3:47:40 PM
// class Solution {
// public:
//     int solve(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>&dp){
//         int n = nums.size();
//         if(ind == n)return 0;

//         if(dp[ind][prev_ind + 1] != -1)return dp[ind][prev_ind + 1];

//         int take = 0;
//         if(prev_ind == -1 || nums[prev_ind] < nums[ind]){
//             take = 1 + solve(ind + 1,ind,nums,dp);
//         }
//         int notTake = solve(ind + 1,prev_ind,nums,dp);

//         return dp[ind][prev_ind + 1] = max(take,notTake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int ind = n - 1; ind >= 0; ind--) {
//             for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
//                 dp[ind][prev_ind + 1] = max(dp[ind + 1][prev_ind + 1], dp[ind][prev_ind + 1]);

//                 if (prev_ind == -1 || nums[prev_ind] < nums[ind]) {
//                     dp[ind][prev_ind + 1] = max(dp[ind][prev_ind + 1], 1 + dp[ind + 1][ind + 1]);
//                 }
//             }
//         }

//         return dp[0][0];
//     }
// };

// class Solution {
// public:
//     int lis(int ind,int prev,vector<int>nums){
//         if(ind == nums.size())return 0;
//         int take = 0;
//         if(prev == -1 || nums[ind] > nums[prev]){
//             take = 1 + lis(ind + 1,ind,nums);
//         }
//         int notTake = 0;
//         notTake = lis(ind + 1,prev,nums);
//         return max(take,notTake);
//     }
//     int lis_mem(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
//         if(ind == nums.size())return 0;

//         if(dp[ind][prev + 1] != -1)return dp[ind][prev + 1];
        
//         int take = 0;
//         if(prev == -1 || nums[ind] > nums[prev]){
//             take = 1 + lis_mem(ind + 1,ind,nums,dp);
//         }
//         int notTake = 0;
//         notTake = lis_mem(ind + 1,prev,nums,dp);
//         return dp[ind][prev + 1] = max(take,notTake);
//     }
//     int lis_tab(vector<int>nums){
//         int n = nums.size();
//         vector<vector<int>>dp(n + 1,vector<int>(n + 1,0));
//         for(int ind = n - 1;ind >= 0;ind--){
//             for(int prev = -1;prev < n;prev++){
//                 int take = 0;
//                 if(prev == -1 || nums[ind] > nums[prev]){
//                     take = 1 + dp[ind + 1][ind + 1];
//                 }
//                 int notTake = dp[ind + 1][prev + 1];
//                 dp[ind][prev + 1] = max(take,notTake);
//             }
//         }
//         return dp[0][0];
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>>dp(n,vector<int>(n + 1 , -1));
//         // return lis(0,-1,nums);
//         // return lis_mem(0, -1 ,nums,dp);
//         return lis_tab(nums);
//     }
// };

//using Binary Search
//Binary search approach is based on the principle that if number(num) greater than x (num > x), 
//then that number is also greater than a number less than x (x0),ie., num > x && x > x0 <=> num > x0
// Try the example to understand : 3 1 4 2 3 4
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>sub;
        for(int i = 0;i < n;i++){
            if(sub.empty() || sub.back() < nums[i]){
                sub.push_back(nums[i]);
            }else{
                auto it = lower_bound(sub.begin(),sub.end(),nums[i]);
                *it = nums[i];
            }
        }
        return sub.size();
    }
};


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n,1);
//         int ans = 1;
//         for(int i = 0;i<n;i++){
//             for(int prev = 0;prev<i;prev++){
//                 if(nums[prev] < nums[i]){
//                     dp[i] = max(dp[i],1 + dp[prev]);
//                 }
//             }
//             ans = max(ans,dp[i]);
//         }
//         return ans;
//     }
// };


//optimal space tabulation
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>>dp(n + 1,vector<int>(n+1,0));
//         vector<int>next(n+1,0);
//         vector<int>curr(n+1,0);
//         for(int ind = n - 1;ind >= 0;ind--){
//             for(int prev = ind - 1;prev >= -1;prev--){
//                 int len = next[prev + 1];
//                 if(prev == -1 || nums[ind] > nums[prev]){
//                     len = max(len, 1 + next[ind + 1]);
//                 }
//                 curr[prev + 1] = len;
//             }
//             next = curr;
//         }
//         return next[-1 + 1];
//     }
// };

//tabulation
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>>dp(n + 1,vector<int>(n+1,0));
//         for(int ind = n - 1;ind >= 0;ind--){
//             for(int prev = ind - 1;prev >= -1;prev--){
//                 int len = dp[ind + 1][prev+1];
//                 if(prev == -1 || nums[ind] > nums[prev]){
//                     len = max(len, 1 + dp[ind + 1][ind + 1]);
//                 }
//                 dp[ind][prev + 1] = len;
//             }
//         }
//         return dp[0][-1 + 1];
//     }
// };


// memoization
// class Solution {
// public:
//     vector<vector<int>>dp;
//     int LIS(int ind,int prev,vector<int>&nums){
//         int n =  nums.size();
//         if(ind == n)return 0;
//         if(dp[ind][prev + 1] != -1){
//             return dp[ind][prev + 1];
//         }
//         int len = LIS(ind + 1,prev,nums);
//         if(prev == -1 || nums[ind] > nums[prev]){
//             len =  max(len,1 + LIS(ind + 1,ind,nums));
//         }
//         return dp[ind][prev + 1] = len;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         dp = vector<vector<int>>(n,vector<int>(n+1,-1));
//         return LIS(0,-1,nums);
//     }
// };