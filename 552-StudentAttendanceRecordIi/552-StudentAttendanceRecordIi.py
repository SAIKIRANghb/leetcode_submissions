# Last updated: 11/25/2026, 3:46:58 PM
# class Solution:
#     def checkRecord(self, n: int) -> int:
#         ## if a < 2 solve(i + 1, a + 1,0)
#         ## if b < 3 solve(i + 1, a, b + 1)
#         ## solve(i + 1, a, 0)

#         MOD: int = 10**9 + 7

#         dp: list[list[int]] = [[[0] * 4 for _ in range(3)] for _ in range(n + 1)]

#         for j in range(3):
#             for k in range(4):
#                 dp[n][j][k] = 1
        
#         for i in range(n - 1, -1, -1):
#             for j in range(1, -1, -1):
#                 for k in range(2, -1, -1):
#                     if j < 1:
#                         dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j + 1][0])
#                     if k < 2:
#                         dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][k + 1]) 
                    
#                     dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][0])

#                     dp[i][j][k] %= MOD
        
#         return dp[0][0][0] % MOD

class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10**9 + 7

        dp = [[[0] * 4 for _ in range(3)] for _ in range(n + 1)]


        for j in range(2):
            for k in range(3):
                dp[0][j][k] = 1
                
        for i in range(1, n + 1):
            for j in range(1, -1, -1):
                for k in range(2, -1, -1):

                    # P
                    dp[i][j][k] += dp[i - 1][j][0]

                    # A
                    if j < 1: # j < 2 and k < 3 also works in 1 -> n dp , bcz smhow the invalid rounds add to 0
                        dp[i][j][k] += dp[i - 1][j + 1][0]

                    # L
                    if k < 2:
                        dp[i][j][k] += dp[i - 1][j][k + 1]

                    dp[i][j][k] %= MOD

        return dp[n][0][0]
