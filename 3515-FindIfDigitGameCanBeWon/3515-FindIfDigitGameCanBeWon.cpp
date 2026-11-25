// Last updated: 11/25/2026, 3:38:52 PM
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int grtSum = 0;
        int smallSum = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] >= 10){
                grtSum += nums[i];
            }else{
                smallSum += nums[i];
            }
        }
    if(smallSum != grtSum)return true;
        return false;
    }
};