// Last updated: 11/25/2026, 3:38:26 PM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size() , m = moveTime[0].size();

        //define dimensions correctly or without any error also the code works wrongly , 
        // by accessing restricted areas without any errors (since it is a vector)
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        // {t , i , j} make some tweaks on dijkstra to apply here
        pq.push({0,0,0});

        while(!pq.empty()){
            vector<int>top = pq.top();
            pq.pop();
            int t = top[0];
            int x = top[1];
            int y = top[2];

            if(x == n - 1 && y == m - 1)return t;

            if(vis[x][y]) continue;  // Skip if already visited

            vis[x][y] = true;

            vector<int>dx = {-1,1,0,0};
            vector<int>dy = {0,0,1,-1};

            for(int i = 0;i < 4;i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX < n && newY < m && newX >= 0 && newY >= 0 && !vis[newX][newY]){
                    //taking the moveTime[newX][newY] directly can cause infinte loop 
                    //of moving back and forth because the cost will not increase instead decreases.
                    //eg : move from t = (node1)t = 4 -> (node2)t = 3 and again 
                    //move to (node2)t = 3 -> (node1)t = 4 , enters infinite loop
                    //it is both correct and safe to take max(t,moveTime[newX][newY])

                    //time has already passed or has to pass + 1 (+1 for moving)
                    int nextTime = max(t,moveTime[newX][newY]) + 1;
                    pq.push({nextTime, newX,newY});
                }   
            }
        }
        return -1;
    }
};

