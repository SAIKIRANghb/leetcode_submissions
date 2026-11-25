// Last updated: 11/25/2026, 3:40:12 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long sumMiss = 0;
        long long sqSum = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                sumMiss += grid[i][j];
                sqSum += grid[i][j] * grid[i][j];
            }
        }
        int numEl = n * n;
        int sumCrct = (numEl * (numEl + 1)) / 2;
        int x_y = sumCrct - sumMiss;
        long long sqSumCrct = (numEl * (numEl + 1) * 1LL*(2*numEl + 1)) / 6;
        long long x2_y2 = sqSumCrct - sqSum;
        long long xplusy = x2_y2 / x_y;
        int x = (xplusy + x_y) / 2;
        int y = (xplusy - x_y) / 2;
        return {y , x};
    }
};