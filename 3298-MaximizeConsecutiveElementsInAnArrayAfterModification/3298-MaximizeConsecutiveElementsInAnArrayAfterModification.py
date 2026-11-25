# Last updated: 11/25/2026, 3:40:03 PM
class Solution:
    def maxSelectedElements(self, nums: List[int]) -> int:
        dp: dict[int,int] = {}

        nums.sort()

        for num in nums:
            dp[num + 1] = dp.get(num,0) + 1
            dp[num] = dp.get(num - 1,0) + 1
            ## ans = max(ans, dp[num] , dp[num + 1])

        return max(dp.values()) 