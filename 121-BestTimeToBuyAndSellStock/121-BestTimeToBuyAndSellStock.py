# Last updated: 11/25/2026, 3:49:02 PM
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        
        n: int = len(prices)
        minEl: int = prices[0]
        profit: int = 0

        for i in range(n):
            if minEl > prices[i]:
                minEl = prices[i]

            profit = max(profit, prices[i] - minEl)
        
        return profit
