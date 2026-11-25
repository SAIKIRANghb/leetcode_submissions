// Last updated: 11/25/2026, 3:39:52 PM
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ops = 0;
        for(int i = 1;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i - 1][j] >= grid[i][j]){
                    ops += grid[i - 1][j] - grid[i][j] + 1;
                    grid[i][j] = grid[i - 1][j] + 1;
                }
            }
        }
        return ops;
    }
};