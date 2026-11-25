# Last updated: 11/25/2026, 3:45:21 PM
class Solution:
    def findUpperBnd(self, num: int, days: list[int]) -> int:
        l = 0
        r = len(days)

        while l < r:
            ## mid = l + (r - l + 1) // 2
            mid = l + (r - l) // 2  

            if days[mid] <= num:
                ## l = mid
                l = mid + 1
            else:
                ## r = mid - 1 
                r = mid

        ## return l + 1
        return l 

    def mincostTickets(self, days: list[int], costs: list[int]) -> int:

        n = len(days)

        dp = [float('inf')] * (n + 1)
        dp[n] = 0

        for i in range(n - 1, -1, -1):

            j = self.findUpperBnd(days[i], days)
            k = self.findUpperBnd(days[i] + 6, days)
            l = self.findUpperBnd(days[i] + 29, days)

            dp[i] = min(
                costs[0] + dp[j],
                costs[1] + dp[k],
                costs[2] + dp[l]
            )

        return dp[0]