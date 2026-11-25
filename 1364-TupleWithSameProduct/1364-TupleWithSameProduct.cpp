// Last updated: 11/25/2026, 3:44:20 PM
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i = 0;i < n;i++){
            int a = nums[i];
            for(int j = i + 1;j < n;j++){
                int b = nums[j];
                int prod = a * b;
                mp[prod]++;
            }
        }

        for(auto [key , values] : mp){
            ans += ((values * (values - 1)) / 2) * 8;
        }
        return ans;
    }
};