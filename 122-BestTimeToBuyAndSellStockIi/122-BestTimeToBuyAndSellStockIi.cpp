// Last updated: 11/25/2026, 3:49:00 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_min = INT_MAX;
        int curr_min = prices[0];

        int prev_ans = -1;

        for(int i = 1;i < prices.size();i++){
            if(prices[i] > curr_min) {
                int curr_ans = prices[i] - curr_min;

                if(prev_ans != -1) {
                    prev_ans = curr_ans + prev_ans;
                }else{
                    prev_ans = curr_ans;
                }

                prev_min = curr_min;
                curr_min = prices[i];
            }
            else curr_min = min(curr_min, prices[i]);
        }

        return prev_ans == -1 ? 0 : prev_ans;
    }
};