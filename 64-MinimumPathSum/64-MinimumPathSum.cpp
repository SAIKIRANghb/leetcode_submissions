// Last updated: 11/25/2026, 3:49:39 PM
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m + 1,vector<int>(n + 1, INT_MAX));
        dp[0][0] = grid[0][0];
        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                if(i == m - 1 && j == n - 1){dp[i][j] = grid[i][j]; continue;}
                
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j],dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};














// class Solution {
// public:
//     vector<vector<int>>dp;
//     int solve(vector<vector<int>>& grid,int i,int j){
//         int m = grid.size();
//         int n = grid[0].size();
//         if(i == m - 1 && j == n - 1)return grid[i][j];
//         if(i > m - 1 || j > n - 1){
//             return INT_MAX;
//         }
//         if(dp[i][j] != -1)return dp[i][j];
//         return dp[i][j] = grid[i][j] + min(solve(grid,i + 1,j) , solve(grid,i,j + 1));
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         dp = vector<vector<int>>(m,vector<int>(n,-1));
//         return solve(grid,0,0);
//     }
// };