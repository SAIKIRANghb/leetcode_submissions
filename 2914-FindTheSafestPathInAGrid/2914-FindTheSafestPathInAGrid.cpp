// Last updated: 11/25/2026, 3:40:37 PM
class Solution {
public:
    bool isSafe(int safeDis , vector<vector<int>>& disVec){
        if(disVec[0][0] < safeDis)return false;
        int m = disVec.size();
        int n = disVec[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int, int>> q;
        q.push({0,0});   
        visited[0][0] = 1;
        while(!q.empty()){
            pair<int,int> pos = q.front();
            int x = pos.first;
            int y = pos.second;
            q.pop();
            if(x == n-1 && y == n-1)return true;
                if (x < m-1) {
                    if(disVec[x+1][y] >= safeDis){
                    if(!visited[x+1][y]){
                        q.push({x + 1, y});
                        visited[x+1][y] = 1;
                    }
                    }
                }
                if (y < n-1) {
                    if(disVec[x][y+1] >= safeDis){
                    if(!visited[x][y+1]){
                        q.push({x, y + 1});
                        visited[x][y+1] = 1;
                    }
                    }
                }
                if (x > 0) {
                    if(disVec[x-1][y] >= safeDis){
                    if(!visited[x-1][y]){
                        q.push({x - 1, y});
                        visited[x-1][y] = 1;
                    }
                    }
                }
                if (y > 0) {
                    if(disVec[x][y-1] >= safeDis){
                    if(!visited[x][y-1]){
                        q.push({x, y - 1});
                        visited[x][y-1] = 1;
                    }
                    }
                }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>disVec(m,vector<int>(n,0));
        vector<vector<int>>visited(m,vector<int>(n,0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    disVec[i][j] = 0;
                }
            }
        }
        int len = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> pos = q.front();
                int x = pos.first;
                int y = pos.second;
                q.pop();
                disVec[x][y] = len;
                if (x < m-1) {
                    if(!visited[x+1][y]){
                        q.push({x + 1, y});
                        visited[x+1][y] = 1;
                    }
                }
                if (y < n-1) {
                    if(!visited[x][y+1]){
                        q.push({x, y + 1});
                        visited[x][y+1] = 1;
                    }
                }
                if (x > 0) {
                    if(!visited[x-1][y]){
                        q.push({x - 1, y});
                        visited[x-1][y] = 1;
                    }
                }
                if (y > 0) {
                    if(!visited[x][y-1]){
                        q.push({x, y - 1});
                        visited[x][y-1] = 1;
                    }
                }
            }
            len++;
        }
        int low = 0 ,high = len;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isSafe(mid,disVec)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }

};

