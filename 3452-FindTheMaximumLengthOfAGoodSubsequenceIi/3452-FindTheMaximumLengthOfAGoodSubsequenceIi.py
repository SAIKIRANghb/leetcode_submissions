# Last updated: 11/26/2026, 11:21:30 AM
# class Solution:
#     def maximumLength(self, nums: List[int], k: int) -> int:

#         n: int = len(nums)

#         dp: list[list[int]] = [[1] * (k + 1) for _ in range(n + 1)]

#         for i in range(n - 1, -1, -1):
#             for prev in range(0, i):
#                 for vk in range(k + 1):
                    
#                     if nums[prev] != nums[i]:
#                         if vk > 0:
#                             dp[prev][vk] = max(dp[prev][vk], 1 + dp[i][vk - 1])
#                     else:
#                         dp[prev][vk] = max(dp[prev][vk], 1 + dp[i][vk])
        
#         return max(dp[i][k] for i in range(n))




from collections import defaultdict
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:

        dp = defaultdict(lambda: [0] * (k + 1))

        best1 = [0] * (k + 1)
        best2 = [0] * (k + 1)
        best1_val = [None] * (k + 1)

        for x in nums:

            old = dp[x]
            updates = [0] * (k + 1)

            # Calculate transitions BEFORE updating global bests
            for j in range(k + 1):

                same = old[j]

                different = 0
                if j > 0:
                    if best1_val[j - 1] == x:
                        different = best2[j - 1]
                    else:
                        different = best1[j - 1]

                updates[j] = 1 + max(same, different)

            # Apply updates
            for j in range(k + 1):

                dp[x][j] = updates[j]
                val = updates[j]

                if best1_val[j] == x:
                    best1[j] = val

                elif val > best1[j]:
                    best2[j] = best1[j]
                    best1[j] = val
                    best1_val[j] = x

                elif val > best2[j]:
                    best2[j] = val

        return best1[k]
