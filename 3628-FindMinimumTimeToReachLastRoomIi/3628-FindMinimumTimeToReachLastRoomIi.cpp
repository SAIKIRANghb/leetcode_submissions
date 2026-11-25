// Last updated: 11/25/2026, 3:38:25 PM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        // Store {time, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;  // Min heap instead of max heap
        vector<vector<bool>> visited(m, vector<bool>(n, false));  // visited array
        
        pq.push({0, 0, 0, 1});
        
        while(!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            
            int pathTime = top[0];
            int topX = top[1];
            int topY = top[2];
            int numMoves = top[3];

            if(topX == m - 1 && topY == n - 1) return pathTime;
            
            if(visited[topX][topY]) continue;  // Skip if already visited
            visited[topX][topY] = true;
            
            vector<int> dx = {-1, 0, 1, 0};  
            vector<int> dy = {0, 1, 0, -1};  
            
            for(int i = 0; i < 4; i++) {
                int newX = topX + dx[i];
                int newY = topY + dy[i];
                
                // Fixed boundary condition check
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    // Calculate next time based on moveTime requirement
                    int nextTime;
                    if(numMoves == 1){
                        nextTime = max(pathTime, moveTime[newX][newY]) + 1;
                        pq.push({nextTime, newX, newY,2});
                    }else{
                        nextTime = max(pathTime, moveTime[newX][newY]) + 2;
                        pq.push({nextTime, newX, newY,1});
                    }
                }
            }
        }
        return -1;
    }
};