// Last updated: 11/25/2026, 3:45:26 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size() / 2;

        sort(nums.begin(), nums.end());

        if(nums[n - 1] == nums[n - 2]){
            return nums[n - 1];
        }else{
            return nums[n];
        }
    }
};