// Last updated: 11/25/2026, 3:44:12 PM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        // Initialize base cases
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = matrix[0][j];
            ans += dp[0][j];
        }

        // Fill the dp table and calculate answer
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int left = dp[i][j - 1];
                    int diagonal = dp[i - 1][j - 1];
                    int top = dp[i - 1][j];
                    dp[i][j] = 1 + min(left, min(diagonal, top));
                    ans += dp[i][j];
                }
            }
        }

        return ans;
    }
};



// class Solution {
// public:
//     vector<vector<int>>dp;
//     int solve(int i,int j,vector<vector<int>>& matrix){
//         if(i < 0 || j < 0)return 0;
//         if(matrix[i][j] != 1)return 0;

//         if(dp[i][j] != -1)return dp[i][j];

//         int left = solve(i,j - 1,matrix);
//         int diagonal = solve(i - 1,j - 1,matrix);
//         int up = solve(i - 1,j,matrix);

//         return dp[i][j] = 1 + min(left,min(diagonal,up));
//     }
//     int countSquares(vector<vector<int>>& matrix) {
//         int m = matrix.size(),n = matrix[0].size();
//         int ans = 0;
//         dp = vector<vector<int>>(m,vector<int>(n,-1));
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 ans += solve(i,j,matrix);
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>>dp;

//     int solve(int i,int j,vector<vector<int>>& grid){
//         if(i >= grid.size() || j >= grid[0].size())return 0;
//         if(grid[i][j] != 1)return 0;
//         if(dp[i][j] != -1)return dp[i][j];
//         int right = solve(i,j + 1,grid);
//         int diagonal = solve(i + 1,j + 1,grid);
//         int below = solve(i + 1,j,grid);
//         return dp[i][j] = 1 + min({right,diagonal,below});
//     }

//     int countSquares(vector<vector<int>>& matrix) {
//         int m = matrix.size(),n = matrix[0].size();
//         dp = vector<vector<int>>(m,vector<int>(n,-1));
//         int ans = 0;
//         for(int i=0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 ans += solve(i,j,matrix);
//             }
//         }
//         return ans;
//     }
// };