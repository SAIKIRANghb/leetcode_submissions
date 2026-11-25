// Last updated: 11/25/2026, 3:41:11 PM
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int i = 0 , j = 0;
        int currPairs = 0;
        long long numSubarrays = 0;
        while(j < n){
            currPairs += mp[nums[j]];
            mp[nums[j]]++;
            while(currPairs >= k){
                numSubarrays += (n - j);
                mp[nums[i]]--;
                currPairs -= mp[nums[i]]; 
                i++;
            }
            j++;
        }
        return numSubarrays;
    }
};