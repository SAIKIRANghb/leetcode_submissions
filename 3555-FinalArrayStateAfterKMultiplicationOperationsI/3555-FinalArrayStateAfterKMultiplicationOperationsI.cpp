// Last updated: 11/25/2026, 3:38:37 PM
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        
        for(int i = 0;i< k;i++){
            vector<int> top = pq.top();
            top[0] *= multiplier;
            pq.pop();
            nums[top[1]] = top[0];
            pq.push({top[0],top[1]});
        }
        
        return nums;
    }
};