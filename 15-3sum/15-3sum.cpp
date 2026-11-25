// Last updated: 11/25/2026, 3:50:15 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;

        // Sort the input array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate numbers for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int remTarget = 0 - nums[i];  // Remaining target for two-sum
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < remTarget) {
                    left++;
                } else if (sum > remTarget) {
                    right--;
                } else {
                    // Found a valid triplet
                    output.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move pointers after processing the current triplet
                    left++;
                    right--;
                }
            }
        }
        return output;
    }
};
