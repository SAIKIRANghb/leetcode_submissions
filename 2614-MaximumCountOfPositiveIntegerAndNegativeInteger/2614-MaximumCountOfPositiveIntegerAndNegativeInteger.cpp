// Last updated: 11/25/2026, 3:41:14 PM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(nums[mid] >= 0){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        int Exzero = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int ans = max(low, n - Exzero);

        return ans;
    }
};