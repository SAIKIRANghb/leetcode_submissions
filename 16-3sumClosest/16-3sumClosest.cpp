// Last updated: 11/25/2026, 3:50:13 PM
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  // Sort the array
        int closestSum = nums[0] + nums[1] + nums[2];  // Initialize to the first triplet

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closestSum if the current sum is closer to the target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move the pointers based on comparison
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // If the currentSum equals the target, return it immediately
                    return currentSum;
                }
            }

            // Skip duplicate values for `nums[i]`
            while (i < n - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return closestSum;
    }
};
