// Last updated: 11/25/2026, 3:41:53 PM
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0;i < n;i++){
            pq.push(nums[i]);
        }

        long long ans = 1;

        while(k--) {
            int minEl = pq.top();
            pq.pop();
            pq.push(minEl + 1);
        }
        while(!pq.empty()){
            ans = (ans * pq.top()) % MOD;
            pq.pop();
        }
        return ans;
    }
};