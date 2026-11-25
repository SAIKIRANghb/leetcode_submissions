# Last updated: 11/25/2026, 3:37:40 PM
class Solution:
    def countDominantElements(self, nums: list[int]) -> int:
        n: int = len(nums)

        if n == 1:
            return 1
            
        cnt: int = 0
        
        for i in range(1,n - 1):
            if (nums[i - 1] + nums[i + 1]) / 2 <= nums[i] :
                cnt += 1

        if nums[0] >= nums[1]:
            cnt += 1
        if nums[n - 1] >= nums[n - 2]:
            cnt += 1
        return cnt