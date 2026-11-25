// Last updated: 11/25/2026, 3:45:08 PM
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        queue<pair<int,int>>QUEUE;

        for(int i = 0;i < m;i++){
            if(grid[i][0] == 1){
                vis[i][0] = true;
                grid[i][0] = 0;
                QUEUE.push({i,0});
            }
            if(grid[i][n - 1] == 1){
                vis[i][n - 1] = true;
                grid[i][n - 1] = 0;
                QUEUE.push({i, n - 1});
            }
        }

        for(int j = 1;j < n;j++){
            if(grid[0][j] == 1){
                vis[0][j] = true;
                grid[0][j] = 0;
                QUEUE.push({0,j});
            }

            if(grid[m - 1][j] == 1){
                vis[m - 1][j] = true;
                grid[m - 1][j] = 0;
                QUEUE.push({m - 1,j});
            }
        }

        while(!QUEUE.empty()){
            int x = QUEUE.front().first;
            int y = QUEUE.front().second;
            QUEUE.pop();
            vector<int>dx = {0, 0, 1, -1};
            vector<int>dy = {1, -1, 0, 0};

            for(int i = 0;i < 4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newy >= 0 && newx < m && newy < n && !vis[newx][newy] && grid[newx][newy] == 1){
                    grid[newx][newy] = 0;
                    vis[newx][newy] = true;
                    QUEUE.push({newx,newy});
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1)cnt++;
            }
        }
        return cnt;
    }
};