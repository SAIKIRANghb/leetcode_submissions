// Last updated: 11/25/2026, 3:39:36 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        int parity = nums[0]%2;
        for(int i=0;i<n;i++){
            if(nums[i]%2 != parity){
                return false;
                break;
            }
            parity = !parity;
        }
        return true;
    }
};