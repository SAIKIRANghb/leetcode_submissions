// Last updated: 11/25/2026, 3:46:07 PM


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int prevCount = 0;
        int count = 0;
        int start = 0,end = 0;
        for(int i=0;i<n;i++){
            if(left <= nums[i] && nums[i]<=right){
                prevCount = end - start + 1;
                count += prevCount;
            }else if(nums[i] < left){
                count += prevCount;
            }else if(nums[i] > right){
                start = end + 1;
                prevCount = 0;
            }
            end++;
        }
        return count;
    }
};