# Last updated: 11/25/2026, 3:47:07 PM
class Solution:
    def change(self, amount: int, coins: list[int]) -> int:

        n: int = len(coins)
                                            ##bcz amount need to be 1-based index
        dp: list[list[int]] = [[0] * (amount + 1) for _ in range(n + 1)] ## bcz has n as base case

        for i in range(0, n + 1):
            dp[i][0] = 1
        
        for i in range(n - 1, -1, -1):
            for j in range(1, amount + 1):

                if j - coins[i] >= 0: 
                    dp[i][j] = dp[i][j] + dp[i][j - coins[i]]
                    
                dp[i][j] = dp[i][j] + dp[i + 1][j]
        
        return dp[0][amount]
        
