// Last updated: 11/25/2026, 3:42:48 PM
class Solution {
public:
    int solve(int ind ,int xorSum,vector<int>& nums){
        int n = nums.size();
        if(ind == n)return xorSum;
        int take = solve(ind + 1,xorSum ^ nums[ind],nums);
        int notTake = solve(ind + 1,xorSum,nums);
        return take + notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,0,nums);
    }
};