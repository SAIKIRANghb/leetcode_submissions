# Last updated: 11/25/2026, 3:46:26 PM
class Solution:
        
    #We don't need to explicitly remove the next number. "x + 1" for a chosen x.
    #The DP recurrence ensures that adjacent numbers are never selected together.

    def deleteAndEarn(self, nums: list[int]) -> int:

        ## note that we are iterating over the "max(array numbers) + 1" range
        ## this implicitly handles the tracking of ignoring "x +- 1" conditions 

        points: list[int] = [0] * (max(nums) + 1)

        for num in nums:
            points[num] += num
        
        n: int = len(points)

        # we can do (n + 1) against n to prevent explicit edge case handling
        dp: list[int] = [0] * n

        dp[n - 1] = points[n - 1]
                                # + dp[n] == 0 [invalid]    
        dp[n - 2] = max(dp[n - 1], points[n - 2]) 

        for i in range(n - 3, -1, -1):

#     ## dp[i + 1] ==> doesn't pick current, can continue with i + 1
#     ## dp[i + 2] ==> pick current & add score, should ignore "i + 1", so move to i + 2
#     ## no need of explicit "i - 1" case because it is implicit

            dp[i] = max(dp[i + 1], points[i] + dp[i + 2])
        
        return dp[0]
        