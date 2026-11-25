// Last updated: 11/25/2026, 3:46:31 PM
class Solution {
public:
    int NoOfValsLessThanMid(vector<int>& nums, int mid) {
        int i = 0, j = 1;
        int count = 0;
        while (j < nums.size()) {
            while (i < j && abs(nums[i] - nums[j]) > mid) {
                i++;
            }
            count += (j - i);
            j++;
        }
        return count;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[n - 1] - nums[0]; 
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;  // Fixed this line
            int NoL = NoOfValsLessThanMid(nums, mid);
            if (NoL < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
