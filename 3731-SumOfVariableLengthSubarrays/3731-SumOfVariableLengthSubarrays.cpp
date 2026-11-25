// Last updated: 11/25/2026, 3:37:55 PM
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> pref(n, 0);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
        }
        
        int sum = 0;
        int start = 0;
        
        for (int i = 0; i < n; i++) {
            start = max(0, i - nums[i]);
            if (start > 0) {
                sum += pref[i] - pref[start - 1];
            } else {
                sum += pref[i];
            }
        }
        
        return sum;
    }
};
