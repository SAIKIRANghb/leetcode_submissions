// Last updated: 11/25/2026, 3:48:39 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        int low = 1 , high = n - 2;

        if(nums[0] < nums[1] && nums[0] < nums[n - 1])return nums[0];
        if(nums[n - 2] > nums[n - 1])return nums[n - 1];

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1])return nums[mid];

            if(nums[mid] <= nums[high]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }
};