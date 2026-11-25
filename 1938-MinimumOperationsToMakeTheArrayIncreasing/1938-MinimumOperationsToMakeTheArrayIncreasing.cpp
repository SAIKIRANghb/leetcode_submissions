// Last updated: 11/25/2026, 3:42:54 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        for(int i = 1;i < n;i++){
            if(nums[i - 1] < nums[i])continue;
            ops += nums[i - 1] - nums[i] + 1;
            nums[i] = nums[i - 1] + 1;
        }
        return ops;
    }
};