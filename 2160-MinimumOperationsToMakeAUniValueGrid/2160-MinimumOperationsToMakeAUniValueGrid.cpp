// Last updated: 11/25/2026, 3:42:25 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        priority_queue<int, vector<int>, greater<int>> pq; 
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        int quotient = grid[0][0] % x;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(quotient != grid[i][j] % x) return -1; 
                pq.push(grid[i][j]);
                if(pq.size() > (total+1) / 2) {
                    pq.pop();
                }
            }
        }
        
        int mid = pq.top(); 
        pq.pop();
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += abs(grid[i][j] - mid) / x; 
            }
        }
        
        return ans;
    }
};
