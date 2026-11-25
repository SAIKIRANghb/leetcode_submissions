// Last updated: 11/25/2026, 3:38:07 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = n - 1;i >= 0;i--){
            if(mp.count(nums[i])){
                return (i + 1 + 2) / 3;
            }
            mp[nums[i]] = true;
        }
        return 0;
    }
};