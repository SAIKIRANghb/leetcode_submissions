// Last updated: 11/25/2026, 3:41:41 PM
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int,int>mp;
        long long goodPair = 0;
        for(int j = 0;j < n;j++){
            int req = nums[j] - j;
            if(mp.count(req)){
                goodPair += mp[req];
            }
            mp[nums[j] - j]++;
        }
        return n*(n - 1)/2 - goodPair;
    }
};