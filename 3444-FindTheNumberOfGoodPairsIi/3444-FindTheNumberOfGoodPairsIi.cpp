// Last updated: 11/25/2026, 3:39:26 PM
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int>mp;
        long long ans = 0;
        for(auto it : nums2){
            mp[it * k]++;
        }
        for(auto num : nums1){
            if(num % k != 0)continue;
            for(int j = 1;j*j <= num;j++){
                if(num % j == 0){
                    int f1 = num / j;
                    int f2 = j;
                    ans += mp[f1];
                    if(f1 != f2){
                        ans += mp[f2]; 
                    }
                }
            }
        }
        return ans;
    }
};