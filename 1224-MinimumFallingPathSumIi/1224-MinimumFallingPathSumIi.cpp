// Last updated: 11/25/2026, 3:44:41 PM
//Method - 1
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int helper(vector<vector<int>>& grid, int prev, int i) {        
        int belowSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (j != prev) {
                int currentSum = grid[i][j];
                
                if (i < n - 1) {
                    if (dp[i + 1][j] == INT_MAX) {
                        currentSum += helper(grid, j, i + 1);
                    } else {
                        currentSum += dp[i + 1][j];
                    }
                }
                
                belowSum = min(belowSum, currentSum);
            }
        }
        
        return dp[i][prev] = belowSum;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int m = grid[0].size();
        if(m==1 && n==1){
            return grid[0][0];
        }
        dp = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        
        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, helper(grid, j, 0));
        }
        return minSum;
    }
};

//Method 2
// class Solution {
// public:
//     vector<vector<int>> dp;
//     int n;
//     int helper(int i,int prev,vector<vector<int>>& grid){
//         if(i == n)return 0;
//         if(dp[i][prev] != -1){
//             return dp[i][prev];
//         }
//         int belowSum = INT_MAX;
//         for(int j=0;j<n;j++){
//             if(j != prev){
//                 belowSum =  min(belowSum,grid[i][j] + helper(i+1,j,grid));
//             }
//         }
//         return dp[i][prev] = belowSum;
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         n = grid.size();
//         dp = vector<vector<int>>(n,vector<int>(n,-1));
//         int ans = INT_MAX;
//         for(int i = 0;i<n;i++){
//             ans = min(ans,grid[0][i] + helper(1,i,grid));
//         }
//         return ans;
//     }
// };