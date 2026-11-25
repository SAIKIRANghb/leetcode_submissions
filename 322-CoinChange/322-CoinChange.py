# Last updated: 11/25/2026, 3:47:34 PM
class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        n: int = len(coins)

        ## asks for min, so cannot initialize with 0
        ## amount needs 1 based index thats why (amount + 1) dimension
        dp: list[list[int]] = [[float('inf')] * (amount + 1) for _ in range(n + 1)]

        ## in above dp init order (amount + 1) , (n + 1) will be n x m for array

        dp[n][0] = 0

        ## in Top-down , i ranges from "0 to n - 1" and amount "amount to 0"
        ## therefore in Tabulation it should be "n - 1 to 0" and "0 to amount" 
        ## the order is most important
        for i in range(n - 1, -1, -1):
            for am in range(amount + 1):

                if am - coins[i] >= 0:
                    # i can take multiple times so no dp[i + 1][...] just dp[i][...]
                    # no need of explicit dp[i + 1][...] case within here because it is
                    # implicitly covered by the next case below
                    dp[i][am] = min(dp[i][am], 1 + dp[i][am - coins[i]])

                dp[i][am] = min(dp[i][am], dp[i + 1][am])

        return dp[0][amount] if dp[0][amount] != float('inf') else -1