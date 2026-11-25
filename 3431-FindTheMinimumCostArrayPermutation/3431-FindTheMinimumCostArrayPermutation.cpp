// Last updated: 11/25/2026, 3:39:33 PM
class Solution {
public:

    int f(int first,int prev,int mask,vector<vector<vector<int>>>&dp,vector<int>&nums,int n){
        int index = __builtin_popcount(mask);

        if(index == n)return dp[first][prev][mask] = abs(nums[first] - prev);
        if(dp[first][prev][mask] != -1)return dp[first][prev][mask];
        dp[first][prev][mask] = INT_MAX;
        for(int i=0;i<n;i++){
            if(!((1<<i) & mask)){
                dp[first][prev][mask] = min(dp[first][prev][mask],abs(prev - nums[i]) + f(first,i,mask + (1<<i),dp,nums,n));
            }
        }
        return dp[first][prev][mask];
    }
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n,vector<int>((1<<n),-1)));

        int answer = INT_MAX, first = 0;

        for(int i = 0;i<n;i++){
            int call = f(i,i,(1<<i),dp,nums,n);
            if(answer > call){
                first = i;
                answer = call;
            }
        }

        vector<int>perm;

        function<void(int,int,int)>backtrack = [&](int first,int prev,int mask){
            int index = __builtin_popcount(mask);
            perm.push_back(prev);
            if(index == n)return;

            for(int i=0;i<n;i++){
                if(!((1<<i) & mask)){
                    if(dp[first][i][mask + (1<<i)] + abs(prev - nums[i]) == dp[first][prev][mask]){
                        backtrack(first,i,mask + (1<<i));
                        return;
                    }
                }
            }
        };
        backtrack(first,first,(1<<first));
        return perm;
    }
};