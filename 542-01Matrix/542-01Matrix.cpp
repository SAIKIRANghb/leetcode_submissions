// Last updated: 11/25/2026, 3:47:02 PM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};
        queue<pair<int,int>>q;
        unordered_map<int,pair<int,int>>mp;
        int cnt = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int dis = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                int x = front.first;
                int y = front.second;
                q.pop();
                for(int i = 0;i < 4;i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if(newX >= 0 && newY >= 0 && newX < m && newY < n && mat[newX][newY] == 1 && ans[newX][newY] == 0){
                        q.push({newX,newY});
                        ans[newX][newY] = dis;
                    } 
                }
            }
            dis++;
        }
        return ans;
    }
};