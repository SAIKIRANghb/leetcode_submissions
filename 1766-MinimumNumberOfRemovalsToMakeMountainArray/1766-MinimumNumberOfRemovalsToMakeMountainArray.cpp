// Last updated: 11/25/2026, 3:43:19 PM
class Solution {
public:
    void leftInc(vector<int>& nums, vector<int>& leftLIS) {
        vector<int> sub;
        for (int i = 0; i < nums.size(); i++) {
            if (sub.empty() || nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                auto lb = lower_bound(sub.begin(), sub.end(), nums[i]);
                *lb = nums[i];
            }
            leftLIS[i] = sub.size();
        }
    }

    void rightInc(vector<int>& nums, vector<int>& rightLIS) {
        vector<int> sub;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (sub.empty() || nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                auto lb = lower_bound(sub.begin(), sub.end(), nums[i]);
                *lb = nums[i];
            }
            rightLIS[i] = sub.size();
        }
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftLIS(n, 0), rightLIS(n, 0);

        // Precompute LIS from left and right
        leftInc(nums, leftLIS);
        rightInc(nums, rightLIS);

        int minAns = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            // Check if it's a valid peak
            if (leftLIS[i] > 1 && rightLIS[i] > 1) {
                int totalLIS = leftLIS[i] + rightLIS[i] - 1;
                minAns = min(minAns, n - totalLIS);
            }
        }

        return minAns;
    }
};
