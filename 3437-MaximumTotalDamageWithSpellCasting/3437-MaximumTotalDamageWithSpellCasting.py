# Last updated: 11/25/2026, 3:39:28 PM
class Solution:
    def maximumTotalDamage(self, power):
        ## note that we are iterating over the "max(array numbers) + 1" range
        ## this implicitly handles the tracking of ignoring "x +- 1, x +- 2" conditions 

        count = {}
    
        ## maintain only unique numbers to reduce memory usage of points array.
        for num in power:
            count[num] = count.get(num, 0) + 1

        nums = sorted(count)

        n = len(nums)

        points = [num * count[num] for num in nums]
          
          # n + 1 for edge case 
        dp = [0] * (n + 1)
        
        # range is on the numbers [1, n], so do "i - 1" for array access
        # and dp is moving from 1 to n , for n to i rec == +, for now -
        for i in range(1, n + 1):

            num = nums[i - 1]

            left = 0
            right = i

            # Upper Bound
            while left < right:
                # note: we are doing UpperBound here, when target non present [lb == ub]
                # finding strictly greater number, where num > target, one ind after equals or 
                # when equals not present just next greater [UpperBound]

                # finding first occurence where num is >= target, if same first occur, or just next greater num [lower bound]
                mid = (left + right) // 2

                if nums[mid] <= num - 3:
                    left = mid + 1
                else:
                    right = mid

            j = left ## gives next num after desired num, no need of "j - 1" bcz dp is 1-based-index

     ## dp[i - 1] ==> doesn't pick current, can continue with i + 1
     ## dp[j] & (j < i) ==> pick current & add score, should ignore "i + 1", "i + 2", so move to j
     ## no need of explicit "i - 1", "i - 2" case because it is implicit

            take = points[i - 1] + dp[j]
            skip = dp[i - 1]

            dp[i] = max(take, skip)

        return dp[n]


# class Solution:
#     def maximumTotalDamage(self, power: List[int]) -> int:
        
#         ## note that we are iterating over the "max(array numbers) + 1" range
#         ## this implicitly handles the tracking of ignoring "x +- 1, x +- 2" conditions 

#         n: int = max(power) + 1

#         points: list[int] = [0] * n

#         ## we can do (n + 2) against n to prevent explicit edge case handling
#         dp: list[int] = [0] * n 
        
#         for num in power:
#             points[num] += num

#         dp[n - 1] = points[n - 1]
#         dp[n - 2] = max(dp[n - 1], points[n - 2])
#         dp[n - 3] = max(dp[n - 2], points[n - 3])

#         for i in range(n - 4, -1, -1):

#     ## dp[i + 1] ==> doesn't pick current, can continue with i + 1
#     ## dp[i + 3] ==> pick current & add score, should ignore "i + 1", "i + 2", so move to i + 3
#     ## no need of explicit "i - 1", "i - 2" case because it is implicit
#             dp[i] = max(dp[i + 1], dp[i + 3] + points[i])
        
#         return dp[0]