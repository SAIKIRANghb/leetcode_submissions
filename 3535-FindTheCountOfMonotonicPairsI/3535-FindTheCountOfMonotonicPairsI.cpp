// Last updated: 11/25/2026, 3:38:42 PM
class Solution {
public:
    int modVal = 1000000007;
    vector<vector<vector<int>>> dp;

    int countPairs(vector<int>& nums, int ind, int prev1, int prev2) {
        if (ind == nums.size()) {
            return 1;
        }
        
        if (prev1 != -1 && dp[ind][prev1][prev2] != -1) {
            return dp[ind][prev1][prev2];
        }

        int ans = 0;
        for (int i = 0; i <= nums[ind]; i++) {
            if ((i >= prev1 && nums[ind] - i <= prev2) || prev1 == -1) {
                ans = (ans + countPairs(nums, ind + 1, i, nums[ind] - i)) % modVal;
            }
        }

        if (prev1 != -1) {
            dp[ind][prev1][prev2] = ans;
        }
        return ans;
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(101, vector<int>(101, -1))); // Assuming nums[i] <= 100
        return countPairs(nums, 0, -1, -1);
    }
};
