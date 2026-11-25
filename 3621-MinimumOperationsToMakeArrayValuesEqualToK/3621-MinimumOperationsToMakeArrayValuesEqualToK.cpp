// Last updated: 11/25/2026, 3:38:28 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ops = 0;
        if(n == 1) {
            if(nums[0] == k)return 0;
            else if(nums[0] > k)return 1;
            else return -1;
        }

        for(int i = n - 2;i >= 0;i--){
            if(nums[i] != nums[i + 1])ops++;
            if(nums[i] < k)return -1;
        }
        if(nums[0] != k){
            ops++;
        }
        return ops;
    }
};