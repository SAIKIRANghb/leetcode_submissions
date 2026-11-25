// Last updated: 11/25/2026, 3:46:27 PM
class Solution {
private:
    vector<int>delRow = {1, -1, 0, 0};
    vector<int>delCol = {0, 0, 1, -1};

    void dfs(int row,int col,int iniColor,int newColor,vector<vector<int>>& image,vector<vector<int>>& ans){
        int m = image.size();
        int n = image[0].size();
        ans[row][col] = newColor;
        for(int i = 0;i < 4;i++){
            int newX = row + delRow[i];
            int newY = col + delCol[i];
            if(newX >= 0 && newY >= 0 && newX < m && newY < n && image[newX][newY] == iniColor
            && ans[newX][newY] != newColor){
                dfs(newX,newY,iniColor,newColor,image,ans);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>ans = image;
        int iniColor = image[sr][sc];
        dfs(sr,sc,iniColor,newColor,image,ans);
        return ans;
    }
};