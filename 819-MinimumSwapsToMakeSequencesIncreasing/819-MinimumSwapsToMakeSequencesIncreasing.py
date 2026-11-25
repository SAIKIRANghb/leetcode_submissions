# Last updated: 11/25/2026, 3:46:05 PM
class Solution:
    
    def minSwap(self, nums1: list[int], nums2: list[int]) -> int:

        n:int = len(nums1)

        if n != len(nums2):
            return -1
        
        dp: list[list[int]] = [[float('inf')] * 2 for _ in range(n + 1)] 

        dp[0][0] = 0
        dp[0][1] = 1

        for i in range(1, n):
            for j in range(2):

                # if there is no requirement of swapping, we can either command to swap or not swap
                if j == 0:
                    if nums1[i - 1] < nums1[i] and nums2[i - 1] < nums2[i]:
                        # commanding that swap is not required
                        dp[i][0] = min(dp[i][0], dp[i - 1][0])
                    if nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i]:
                        # commanding that swap should happen
                        dp[i][0] = min(dp[i][0], dp[i - 1][1])
                
                # if there is requirement of swapping, we can either swap i - 2 or swap i - 1
                if j == 1:
                    if nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i]:
                        # considering to swap i - 1
                        dp[i][1] = min(dp[i][1], 1 + dp[i - 1][0])
                    if nums1[i - 1] < nums1[i] and nums2[i - 1] < nums2[i]:
                        # considering to swap i - 2
                        dp[i][1] = min(dp[i][1], 1 + dp[i - 1][1])

        return int(min(dp[n - 1][0], dp[n - 1][1]))