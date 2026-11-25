// Last updated: 11/25/2026, 3:48:36 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int num = nums[0];
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(cnt == 0){
                cnt = 1;
                num = nums[i];
            }
            else if(nums[i] == num){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return num;
    }
};