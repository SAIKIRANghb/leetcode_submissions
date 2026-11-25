// Last updated: 11/25/2026, 3:40:50 PM
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // numRows            //numCols
        int m = grid.size(),n = grid[0].size();
        int res = 0;

        vector<int>dp(m,0);

        for(int j = 1;j<n;j++){
            int leftTop = 0;
            bool found = false;
            for(int i = 0;i<m;i++){
                int curr = -1;
                int nxtLeftTop = dp[i];
                if(i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i-1][j-1]){
                    curr = max(curr,leftTop + 1);
                }
                if(dp[i] != -1 && grid[i][j] > grid[i][j - 1]){
                    curr = max(curr,dp[i] + 1);
                }
                if(i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1]){
                    curr = max(curr,dp[i + 1] + 1);
                }

                dp[i] = curr;
                found = found || (dp[i] != -1);
                leftTop = nxtLeftTop;
            }
            if(!found){
                break;
            }
            res = j;
        }
        return res;
    }
};


// class Solution {
// public:
//     int maxMoves(vector<vector<int>>& grid) {
//         int m = grid.size();    // NumRows
//         int n = grid[0].size(); // NumCols

//         // stores rightmost col we can reach
//         int res = 0;

//         // dp array stores the maximum number of moves possible to reach each
//         // cell in the current column we're processing

//         vector<int> dp(m, 0);
//         // Iterate through each column from left to right (from col 1)
//         for (int j = 1; j < n; j++) {
//             // leftTop keeps track of dp val from the cell above-left
//             int leftTop = 0;

//             bool found = false;

//             // Iterate through each row in current column
//             for (int i = 0; i < m; i++) {
//                 // curr will store the maximum moves to reach current cell
//                 int cur = -1;

//                 // Store dp[i] for next iteration's leftTop
//                 int nxtLeftTop = dp[i];

//                 // check move from top-left cell (if valid)

//                 if (i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i - 1][j - 1]) {
//                     cur = max(cur, leftTop + 1);
//                 }

//                 // check move from direct left cell (if valid)
//                 if (dp[i] != -1 && grid[i][j] > grid[i][j - 1]) {
//                     cur = max(cur, dp[i] + 1);
//                 }
//                 // Check move from bottom-left cell (if valid)
//                 if (i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1]) {
//                     cur = max(cur, dp[i + 1] + 1);
//                 }

//                 // Update dp array for current cell
//                 dp[i] = cur;
//                 // Update found flag if we can reach current cell
//                 found = found || (dp[i] != -1);
//                 // Update leftTop for next row's iteration
//                 leftTop = nxtLeftTop;
//             }
//             if (!found)
//                 break;
//             // Update result to current column if we can reach it
//             res = j;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int maxMoves(vector<vector<int>>& grid) {
//         int n = grid.size(),m = grid[0].size();
//         vector<vector<int>>dp = vector<vector<int>>(n,vector<int>(m,-1));
//         for(int i=0;i<n;i++){
//             dp[i][m - 1] = 1;
//         }

//         for(int j = m - 2; j >= 0 ;j--){
//             for(int i = 0;i<n;i++){
//                 int x = grid[i][j];
//                 int maxMove = (x < grid[i][j + 1]) * dp[i][j+1];
//                 if(i > 0 && x < grid[i - 1][j + 1]){
//                     maxMove = max(maxMove,dp[i - 1][j + 1]);
//                 }
//                 if(i < n - 1 && x < grid[i + 1][j + 1]){
//                     maxMove = max(maxMove,dp[i+1][j+1]);
//                 }
//                 dp[i][j] = 1 + maxMove;
//             }
//         }
//         int ans = INT_MIN;
//         for(int i = 0;i<n;i++){
//             ans = max(ans,dp[i][0]);
//         }
//         return ans - 1;
//     }
// };

/*
class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>>& grid,int i,int j,int prev){
        int m = grid.size(),n = grid[0].size();
        if(i < 0 || i >= m || j >= n)return 0;
        if(prev >= grid[i][j]){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int c1 = helper(grid,i-1,j+1,grid[i][j]);
        int c2 = helper(grid,i,j+1,grid[i][j]);
        int c3 = helper(grid,i+1,j+1,grid[i][j]);
        return dp[i][j] = max({c1,c2,c3}) + 1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        int ans = INT_MIN;
        for(int i = 0;i<m;i++){
            ans = max(helper(grid,i,0,-1),ans);
        }
       return ans - 1;
    }
};
*/