// Last updated: 11/25/2026, 3:40:24 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        // priority_queue<int>pq;

        // pq.push(nums[0]);

        long long ans = 0;
        int max_i = nums[0];
        for(int j = 1;j < n;j++){
            // pq.push(nums[j]);
            max_i = max(max_i,nums[j]);
            for(int k = j + 1;k < n;k++){
                long long numi = max_i;
                ans = max(ans,1LL*numi * nums[k] - 1LL*nums[j] * nums[k]);
            }
        }
        return ans;
    }
};