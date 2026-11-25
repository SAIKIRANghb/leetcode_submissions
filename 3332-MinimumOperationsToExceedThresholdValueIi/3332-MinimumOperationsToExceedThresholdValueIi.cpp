// Last updated: 11/25/2026, 3:39:55 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            pq.push(nums[i]);
        }
        int ops = 0;
        while(pq.size() >= 2){
            if(pq.top() >= k){
                return ops;
            }
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(1LL*min(x,y) * 2 + 1LL*max(x,y));
            ops++;
        }
        if(pq.top() >= k)return ops;
        return ops + 1;
    }
};