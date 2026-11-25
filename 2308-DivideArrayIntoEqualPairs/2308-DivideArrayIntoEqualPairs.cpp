// Last updated: 11/25/2026, 3:41:57 PM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 1)return false;
        sort(nums.begin(),nums.end());
        for(int i = 1;i < n;i += 2){
            if(nums[i] != nums[i - 1]){
                return false;
            }
        }
        return true;
    }
};