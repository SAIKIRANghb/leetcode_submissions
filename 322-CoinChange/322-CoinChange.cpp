// Last updated: 11/25/2026, 3:47:41 PM
// class Solution {
// public:
//     vector<int> dp;
//     int countRecur(int i, int amount, const vector<int>& coins) {
//         if (amount == 0) return 0;
//         if (amount < 0 || i == coins.size()) return INT_MAX;

//         if(dp[amount] != -1) return dp[amount];

//         int take = countRecur(i, amount - coins[i], coins);
//         int skip = countRecur(i + 1, amount, coins);
//         if(take == INT_MAX){
//             return dp[amount] = skip;
//         }
//         else if(skip == INT_MAX){
//             return dp[amount] = 1 + take;
//         }else if(skip == INT_MAX && take == INT_MAX){
//             return dp[amount] = 0;
//         }

//         return dp[amount] = min(1 + take, skip);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         dp = vector<int>(amount + 1, -1);
//         int ans = countRecur(0, amount, coins);
//         return ans >= 1e9 ? -1 : ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int amount, const vector<int>& coins) {
        if (amount == 0) return 0;
        if (amount < 0 || i == coins.size()) return INT_MAX;

        if (dp[i][amount] != -1) return dp[i][amount];

        int take = solve(i, amount - coins[i], coins);
        int skip = solve(i + 1, amount, coins);

        int ans = skip;
        if (take != INT_MAX) ans = min(ans, 1 + take);

        return dp[i][amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(), vector<int>(amount + 1, -1));
        int ans = solve(0, amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }
};
