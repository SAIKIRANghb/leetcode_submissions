// Last updated: 11/25/2026, 3:41:13 PM
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>pq;
        long long score = 0;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            score += top;
            top = ceil(top/3.0);
            pq.push(top);
        }
        return score;
    }
};