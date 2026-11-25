// Last updated: 11/25/2026, 3:41:26 PM
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n - 1;i++){
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int i = 0;
        for(i = 0;i < n;i++){
            if(nums[i] == 0){
                break;
            }
        }
        int j = i + 1;
        while(j < n){
            if(nums[j] != 0){
                swap(nums[j],nums[i]);
                i++;
            }
            j++;
        }
        return nums;
    }
};