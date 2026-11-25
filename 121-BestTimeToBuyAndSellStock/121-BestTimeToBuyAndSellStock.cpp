// Last updated: 11/25/2026, 3:49:08 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 1 , j = 0;
        int minP = prices[0];
        int n = prices.size();
        int profit = 0;
        if(n == 2){
            if(prices[0] >= prices[1]){
                return 0;
            }else{
                return prices[1] - prices[0];
            }
        }
        for(int x = 1;x<n;x++){
            if(prices[x] < prices[j]){
                minP = prices[x];
                j = x;
                continue;
            }
            profit = max(profit,prices[x] - prices[j]);
        }
        return profit;
    }
};