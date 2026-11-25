// Last updated: 11/25/2026, 3:42:04 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int lessI = 0;
        int greaterI = n - 1;
        vector<int>ans(n,-1);
        for(int i = 0, j = n - 1;i < n;i++,j--){
            if(nums[i] < pivot){
                ans[lessI] = nums[i];
                lessI++;
            }
            if(nums[j] > pivot){
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }
        while(lessI <= greaterI){
            ans[lessI] = pivot;
            lessI++;
        }
        return ans;
    }
};