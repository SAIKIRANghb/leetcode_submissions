// Last updated: 11/25/2026, 3:41:55 PM
class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;

        if(n < 3)return n == 0 ?  0 : IntStream.of(nums).sum() % 10;

        for(int i = 0;i < n;i++){ 
            for(int j = 1;j < n - i;j++){
                nums[j - 1] = (nums[j - 1] + nums[j]) % 10;
            }
        }

        return nums[0];
    }
}