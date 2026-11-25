# Last updated: 11/25/2026, 3:49:24 PM
class Solution:
    def numDecodings(self, s: str) -> int:

        if s[0] == "0": return 0; 

        n :int = len(s)

        dp: list[int] = [0] * (n + 2)

        dp[n] = 1

        for i in range(n - 1, -1, -1):

            if i < n - 1 and s[i + 1] == "0" and s[i] == "0":
                return 0

            if int(s[i]) != 0: dp[i] = dp[i] + dp[i + 1] ## no single zeroes

            if int(s[i : i + 2]) <= 26 and int(s[i : i + 2]) >= 10:
                dp[i] = dp[i] + dp[i + 2]
        
        return dp[0]
