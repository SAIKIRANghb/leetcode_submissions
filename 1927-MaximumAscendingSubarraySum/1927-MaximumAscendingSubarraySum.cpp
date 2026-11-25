// Last updated: 11/25/2026, 3:42:56 PM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxS = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i], ind = i;
            for (int j = i; j < nums.size() - 1; j++) {
                if (nums[j] < nums[j + 1]) {
                    sum += nums[j + 1];
                    ind = j + 1;
                } else {
                    sum = 0;
                }
                maxS = max(sum, maxS);
            }
        }
        return max({maxS,nums[0],nums.back()});
    }
};
