// Last updated: 11/25/2026, 3:46:32 PM
class Solution {
public:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int m, n;

    int CalArea(vector<vector<int>>& visited, vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = 1;
        int area = 1;
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            area += CalArea(visited, grid, ni, nj);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int currentArea = CalArea(visited, grid, i, j);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
};
