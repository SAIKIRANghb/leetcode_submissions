// Last updated: 11/25/2026, 3:43:10 PM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return abs(nums[0]);
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int sumMin = 0;
        int sumMax = 0;
        for(int i = 0;i < n;i++){
            sumMin += nums[i];
            sumMax += nums[i];
            if(sumMax > 0){
                maxSum = max(maxSum,sumMax);
            }else if(sumMax <= 0){
                sumMax = 0;
            }
            if(sumMin <= 0){
                minSum = min(minSum,sumMin);
            }else if(sumMin > 0){
                sumMin = 0;
            }
        }
        return max(abs(minSum),maxSum);
    }
};