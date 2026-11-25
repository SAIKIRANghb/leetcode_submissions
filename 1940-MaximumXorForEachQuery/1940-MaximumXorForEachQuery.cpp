// Last updated: 11/25/2026, 3:42:52 PM
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxK = (1 << maximumBit) - 1;  // max possible value for k with maximumBit bits
        vector<int> ans(n);
        
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;  // Compute cumulative XOR of the entire array.
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = xorSum ^ maxK;  // XOR cumulative XOR with maxK to maximize result.
            xorSum ^= nums[n - 1 - i];  // Remove the last element in the "current" array.
        }

        return ans;
    }
};
