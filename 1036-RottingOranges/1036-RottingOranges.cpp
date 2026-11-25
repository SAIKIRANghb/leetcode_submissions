// Last updated: 11/25/2026, 3:45:18 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2)q.push({i , j});
                if(grid[i][j] == 1)fresh++;
            }
        }
        while(!q.empty()){
            int sz = q.size();
            bool infected = false;
            while(sz--){
                auto front = q.front();
                int x = front.first;
                int y = front.second;
                q.pop();
                if(x + 1 < m && grid[x + 1][y] == 1){
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                    infected = true;
                    fresh--;
                }
                if(y + 1 < n && grid[x][y + 1] == 1){
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                    infected = true;
                    fresh--;
                }
                if(x - 1 >= 0 && grid[x - 1][y] == 1){
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                    infected = true;
                    fresh--;
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 1){
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                    infected = true;
                    fresh--;
                }
            }
            if(infected)time++;
        }
        if(fresh > 0)return -1;
        return time;
    }
};