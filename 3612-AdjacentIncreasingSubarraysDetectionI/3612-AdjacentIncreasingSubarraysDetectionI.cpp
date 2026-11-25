// Last updated: 11/25/2026, 3:38:31 PM
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int runningLen = 1;
        bool prevValid = false || (k == 1);
        cout << prevValid;
        for(int i = 1;i < n;i++){
            if(nums[i - 1] < nums[i] || k == 1){
                runningLen++;
                if(prevValid && runningLen >= k){
                    return true;
                }
                if(runningLen == 2*k){
                    return true;
                }
            }else {
                if(runningLen >= k){
                    prevValid = true;
                }else{
                    prevValid = false;
                }
                runningLen = 1;
            }
        }
        return false;
    }
};