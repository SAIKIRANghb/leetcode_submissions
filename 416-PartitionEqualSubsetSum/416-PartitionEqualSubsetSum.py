# Last updated: 11/25/2026, 3:47:21 PM
class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        ## if S / 2 - num >= 0
        ## solve(i + 1, S / 2 - nums[i]) or solve(i + 1, S / 2)

        n: int = len(nums)
        S: int = sum(nums)

        if S % 2 != 0: 
            return False

        dp: list[list[int]] = [[False] * (S // 2 + 1) for _ in range(n + 1)]

        ## only one base case, not loop because the answer is valid only if we exhausted all the possibilites and reached out of bounds i.e "n"
        dp[n][0] = True

        for i in range(n - 1, -1,-1):
            for remain in range(1, S // 2 + 1):
                if remain - nums[i] >= 0:
                    dp[i][remain] = dp[i][remain] or dp[i + 1][remain - nums[i]]
                
                dp[i][remain] = dp[i][remain] or dp[i + 1][remain]
        
        return dp[0][S // 2]
