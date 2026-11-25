// Last updated: 11/25/2026, 3:40:57 PM
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return lower_bound(nums,upper + 1) - lower_bound(nums,lower);
    }
    long long lower_bound(vector<int>&nums,int value){
        int left = 0, right = nums.size() - 1;
        long long res = 0;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < value){
                res += (right - left);
                left++;
            }
            else{
                right--;
            }
        }
        return res;
    }
};



// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         sort(nums.begin(), nums.end());
//         long long count = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; ++i) {
//             int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
//             int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
//             count += (right - left);
//         }

//         return count;
//     }
// };
