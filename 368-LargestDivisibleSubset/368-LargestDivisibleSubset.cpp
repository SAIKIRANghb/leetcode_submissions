// Last updated: 11/25/2026, 3:47:26 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());

        vector<int>dp(n , 1);
        vector<int>hash(n , -1);
        int lastInd = -1;
        int maxLen = 0;
        for(int i = 0;i < n;i++){
            hash[i] = i;
            for(int prev = 0;prev < i;prev++){
                if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }   
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                lastInd = i;
            }
        }
        if(lastInd == -1)return {};
        vector<int>ans;
        ans.push_back(nums[lastInd]);

        while(lastInd != hash[lastInd]){
            lastInd = hash[lastInd];
            ans.push_back(nums[lastInd]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();

//         sort(nums.begin(),nums.end());

//         vector<int>dp(n , 1);
//         vector<int>hash(n , 1);

//         int lastInd = -1;

//         int maxLen = 0;
//         for(int i = 0;i < n;i++){
//             hash[i] = i;
//             for(int prev = 0;prev < i;prev++){
//                 if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]){
//                     dp[i] = 1 + dp[prev];
//                     hash[i] = prev;
//                 }
//             }
//             if(dp[i] > maxLen){
//                 maxLen = dp[i];
//                 lastInd = i;
//             }
//         }
//         vector<int>ans;

//         ans.push_back(nums[lastInd]);

//         while(hash[lastInd] != lastInd){
//             lastInd = hash[lastInd];
//             ans.push_back(nums[lastInd]);
//         }

//         return ans;
//     }
// };


// class Solution {
// public:
//     // int solve(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>&dp){
//     //     int n = nums.size();
//     //     if(ind == n)return 0;
//     //     if(dp[prev_ind + 1][ind] != -1)return dp[prev_ind + 1][ind];
//     //     int take = 0;
//     //     if(prev_ind == -1 || nums[prev_ind] % nums[ind] == 0)take = 1 + solve(ind + 1,ind,nums,dp);

//     //     int notTake = solve(ind + 1,prev_ind,nums,dp);

//     //     return dp[prev_ind + 1][ind] =max(take,notTake);
//     // }

//     vector<int> largestDivisibleSubset(vector<int>& arr) {
//         int n = arr.size();
//         // vector<vector<int>>dp(n + 1,vector<int>(n, -1));
//         sort(arr.rbegin(),arr.rend());
//         // cout<<solve(0,-1,arr,dp);
//         vector<int> dp(n,1);
//         vector<int> hash(n,1);

//         for(int i = 0;i <= n - 1;i++){
//             hash[i] = i;
//             for(int prev_ind = 0;prev_ind <= i - 1;prev_ind++){
//                 if(arr[prev_ind] < arr[i] && 1 + dp[prev_ind] > dp[i]){
//                     dp[i] = 1 + dp[prev_ind];
//                     hash[i] = prev_ind;
//                 }
//             }
//         }
//         int ans = -1;
//         int lastIndex = -1;

//         for(int i = 0;i <= n-1;i++){
//             if(dp[i] > ans){
//                 ans = dp[i];
//                 lastIndex = i;
//             }
//         }
//         vector<int>temp;
//         temp.push_back(arr[lastIndex]);

//         while(hash[lastIndex] != lastIndex){
//             lastIndex = hash[lastIndex];
//             temp.push_back(arr[lastIndex]);
//         }
//         return temp;
//     }
// };
