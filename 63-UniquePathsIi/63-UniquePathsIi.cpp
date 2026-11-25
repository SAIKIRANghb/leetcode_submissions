// Last updated: 11/25/2026, 3:49:40 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0] = 1;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }else if(i == 0 && j==0){
                    continue;
                }else{
                    int up = 0;
                    int left = 0;
                    if(i > 0){
                        up = dp[i - 1][j];
                    }
                    if(j > 0){
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};












// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]==1){
//             return 0;
//         }
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         dp[0][0] = 1;
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 if(obstacleGrid[i][j] == 1){
//                     dp[i][j] = 0;
//                     continue;
//                 }else if(i == 0 && j == 0){
//                     dp[0][0] = 1;
//                     continue;
//                 }
//                 else{
//                     int up = 0;
//                     if(i > 0){
//                         up = dp[i - 1][j];
//                     }
//                     int left = 0;
//                     if(j > 0){
//                         left = dp[i][j-1];
//                     }
//                     dp[i][j] = up + left;
//                 }
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// class Solution {
// public:
//     vector<vector<int>>dp;
//     int solve(vector<vector<int>>& obstacleGrid, int i,int j){
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//         if(i == m-1 && j == n-1)return 1;
//         if(i < 0 || j < 0 || i > m - 1 || j > n - 1|| obstacleGrid[i][j]==1){
//             return 0;
//         }
//         if(dp[i][j] != -1)return dp[i][j];
//         return dp[i][j] = solve(obstacleGrid,i + 1, j) + solve(obstacleGrid,i, j + 1);
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
//          if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1){
//             return 0;
//         }
//         dp = vector<vector<int>>(m,vector<int>(n,-1));
//         return solve(obstacleGrid,0,0);
//     }
// };