// Last updated: 11/25/2026, 3:47:36 PM
class Solution {
public:
    int max_Profit(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(ind >= prices.size())return 0;
        int profit = 0;
        if(dp[ind][buy] != -1)return dp[ind][buy];
        if(buy == 0){
            profit = max(max_Profit(ind + 1,buy,prices,dp) , -prices[ind] + max_Profit(ind + 1,1 - buy,prices,dp));
        }
        if(buy == 1){
            profit = max(max_Profit(ind + 1,buy,prices,dp) , prices[ind] + max_Profit(ind + 2,1 - buy,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
int max_Profit_tab(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            if (buy == 0) {
                dp[ind][buy] = max(dp[ind + 1][buy], -prices[ind] + dp[ind + 1][1 - buy]);
            }
            if (buy == 1) {
                // Ensure the index does not go out of bounds
                dp[ind][buy] = max(dp[ind + 1][buy], prices[ind] + (ind == n - 1 ? 0 : dp[ind + 2][1 - buy]));
            }
        }
    }
    return dp[0][0];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return max_Profit_tab(prices);
}

}; 