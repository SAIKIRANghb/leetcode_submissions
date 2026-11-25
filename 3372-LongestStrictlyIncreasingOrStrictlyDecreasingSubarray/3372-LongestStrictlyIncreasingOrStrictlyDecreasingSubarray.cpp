// Last updated: 11/25/2026, 3:39:47 PM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int Inc = INT_MIN, Dec = INT_MIN;
        int i0 = 0,j0 = 0,i1 = 0,j1 = 0;
        for(int i = 1;i<n;i++){
            if(nums[i - 1] < nums[i]){
                j0++;
                Inc = max(Inc , j0 - i0 + 1);
            }else{
                i0 = j0;
            }
            if(nums[i - 1] > nums[i]){
                j1++;
                Dec = max(Dec , j1 - i1 + 1);
            }else{
                i1 = j1;
            }   
        }
        int ans = max(Inc,Dec);
        if(ans == INT_MIN)return 1;
        return ans;
    }
};