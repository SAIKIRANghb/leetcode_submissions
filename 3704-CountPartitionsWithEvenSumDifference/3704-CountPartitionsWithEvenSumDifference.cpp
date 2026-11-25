// Last updated: 11/25/2026, 3:38:02 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; 
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int sum = 0; 
        int cnt = 0;

        for (int i = 0; i < n - 1; i++) {
            sum += nums[i]; 
            int suffixSum = totalSum - sum;
            
            if ((sum - suffixSum)% 2== 0) cnt++;
        }
        return cnt;
    }
};
