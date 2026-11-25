// Last updated: 11/25/2026, 3:46:45 PM
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>> pq;
        vector<int>ans_range = {-100000,100000};
        int n = nums.size();
        int Max = INT_MIN;
        for(int i = 0 ; i < n; i++){
            int temp = nums[i][0];
            vector<int>tba = {-temp,0,i};
            Max = max(Max,temp);
            pq.push(tba);
        }
        while(true){
            vector<int>min = pq.top();
            pq.pop();
            if(ans_range[1] - ans_range[0] > Max - (-1*min[0])){
                ans_range[0] = -1*min[0];
                ans_range[1] = Max;
            }
            min[1]++;
            vector<int> cl =  nums[min[2]];
            if(min[1] == cl.size()){
                break;
            }else{
                min[0] = - cl[min[1]];
                Max = max(Max,cl[min[1]]);
                pq.push(min);
            }
        }
        return ans_range;
    }
};