# Last updated: 11/25/2026, 3:46:43 PM
class Solution:
    def numDecodings(self, s: str) -> int:

        MOD: int = 10**9 + 7

        if not s:
            return 0

        n = len(s)
        dp = [0] * (n + 2)

        dp[n] = 1

        for i in range(n - 1, -1, -1):

            # Single-character decoding
            if s[i] == "*":
                dp[i] += 9 * dp[i + 1]
            elif s[i] != "0":
                dp[i] += dp[i + 1]

            # Two-character decoding
            if i < n - 1:

                if s[i] == "*" and s[i + 1] == "*":
                    dp[i] += 15 * dp[i + 2]         ##addition rule not product rule

                elif s[i] == "*":
                    if s[i + 1] <= "6":
                        dp[i] += 2 * dp[i + 2]
                    else:
                        dp[i] += dp[i + 2]

                elif s[i + 1] == "*":
                    if s[i] == "1":
                        dp[i] += 9 * dp[i + 2]
                    elif s[i] == "2":
                        dp[i] += 6 * dp[i + 2]

                elif 10 <= int(s[i:i+2]) <= 26:
                    dp[i] += dp[i + 2]

            dp[i] %= MOD

        return dp[0]
