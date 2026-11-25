# Last updated: 11/25/2026, 3:46:25 PM
class Solution:
    def minCostPath(self, ind: int, cost: list[int], dp: list[int]) -> int:

        if ind >= len(cost):
            return 0
        
        if dp[ind] != -1 : return dp[ind]

        minCost: int = 2**31

        minCost = min(
            minCost,
            cost[ind] + min(
                self.minCostPath(ind + 1, cost, dp),
                self.minCostPath(ind + 2, cost, dp)
            )
        )
        
        dp[ind] = minCost

        return dp[ind]


    def minCostClimbingStairs(self, cost: list[int]) -> int:
        n: int = len(cost)
        
        # Initialize array with 0s. 
        # dp[n] and dp[n+1] act as our base cases (cost of 0 to step beyond the last stair)
        dp: list[int] = [0] * (n + 2)

        # Build the table from right to left
        for i in range(n - 1, -1, -1):
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2])

        # You can start at either index 0 or index 1
        return min(dp[0], dp[1])

    # def minCostClimbingStairs(self, cost: list[int]) -> int:

    #     # dp: list[int] = [-1] * len(cost)

    #     # return min(self.minCostPath(0, cost, dp), self.minCostPath(1, cost, dp))