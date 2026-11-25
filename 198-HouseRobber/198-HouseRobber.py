# Last updated: 11/25/2026, 3:48:11 PM
class Solution:
    def rob(self, nums: list[int]) -> int:

        n: int = len(nums)

        dp: list[list[int]] = [[0] * 2 for _ in range(n + 1)]

        for i in range(n - 1, -1, -1) :
            
            dp[i][0] = max(dp[i + 1][0] , nums[i] + dp[i + 1][1])

            dp[i][1] = dp[i + 1][0]
        
        return dp[0][0]