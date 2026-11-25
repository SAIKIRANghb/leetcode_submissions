// Last updated: 11/25/2026, 3:50:26 PM
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int,int>mp;
//         for(int i = 0;i<n;i++){
//             int rem = target - nums[i];
//             if(mp.find(rem) != mp.end()){
//                 return {mp[rem],i}; 
//             }
//             mp[nums[i]] = i; 
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int j = 0;j<n;j++){
            if(mp.find(target - nums[j]) != mp.end()){
                return {mp[target - nums[j]],j};
            }
            mp[nums[j]] = j;
        }
        return {-1,-1};
    }
};