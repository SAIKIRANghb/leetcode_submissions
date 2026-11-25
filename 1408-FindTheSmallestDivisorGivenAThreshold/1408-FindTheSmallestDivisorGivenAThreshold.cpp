// Last updated: 11/25/2026, 3:44:11 PM
class Solution {
public:
   long long RemSum(vector<int>&nums,int divisor){
        long long sum = 0;
        for(int num : nums){
            sum += (1LL*num + divisor - 1)/divisor;
        }
        return sum;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1,high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(RemSum(nums,mid) <= threshold){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};