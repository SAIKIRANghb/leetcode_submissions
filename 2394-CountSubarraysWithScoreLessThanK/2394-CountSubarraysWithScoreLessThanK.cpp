// Last updated: 11/25/2026, 3:41:50 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};