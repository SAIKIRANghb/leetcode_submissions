# Last updated: 11/25/2026, 3:45:36 PM
class Solution:
    def knightDialer(self, n: int) -> int:

        MOD: int = 10**9 + 7

        jumps: list[list[int]] = [
            [4, 6],
            [6, 8],
            [7, 9],
            [4, 8],
            [3, 9, 0],
            [],
            [1, 7, 0],
            [2, 6],
            [1, 3],
            [2, 4]
        ]

        dp: list[[list[int]]] = [[0] * n for _ in range(10)]

        for cell in range(10):
            dp[cell][n - 1] = 1
        
        for remain in range(n - 2, -1, -1):
            for currCell in range(0,10):
                for nextCell in jumps[currCell]:
                    dp[currCell][remain] = (dp[currCell][remain] + dp[nextCell][remain + 1]) % MOD
        
        return sum(dp[cell][0] for cell in range(10)) % MOD