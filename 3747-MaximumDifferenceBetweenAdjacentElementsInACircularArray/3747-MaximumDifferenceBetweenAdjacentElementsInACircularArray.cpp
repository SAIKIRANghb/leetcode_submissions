// Last updated: 11/25/2026, 3:37:52 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxDiff = max({maxDiff,abs(nums[i]-nums[(i + 1)%n]),abs(nums[(i + 1)%n] - nums[i])});
        }
        return maxDiff;
    }
};