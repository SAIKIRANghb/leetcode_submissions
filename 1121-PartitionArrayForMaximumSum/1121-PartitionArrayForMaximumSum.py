# Last updated: 11/25/2026, 3:45:02 PM
class Solution:
    def maxSumAfterPartitioning(self, arr: list[int], k: int) -> int:
        n: int = len(arr)

        dp: list[int] = [0] * (n + 1)

        dp[0] = 0

        for i in range(n - 1, -1, -1):
            runningMax: int = 0
            for j in range(i, min(i + k, n)):                
                runningMax = max(arr[j], runningMax)

                dp[i] = max(runningMax * (j - i + 1) + dp[j + 1], dp[i])
        
        return dp[0]
                

