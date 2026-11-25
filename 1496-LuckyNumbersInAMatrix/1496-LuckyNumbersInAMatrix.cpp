// Last updated: 11/25/2026, 3:43:57 PM
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
       vector<int>ans;
       for(int i = 0;i<m;i++){
          int minj = -1;
          int min = INT_MAX;
          for(int j = 0;j<n;j++){
             if(min > matrix[i][j]){
                min = matrix[i][j];
                minj = j;
             }
          }
          int maxy = -1;
          int max = INT_MIN;
          for(int y = 0;y<m;y++){
              if(max < matrix[y][minj]){
                 max = matrix[y][minj];
                 maxy = y;
              }
          }
          if(matrix[maxy][minj] == matrix[i][minj]){
            ans.push_back(matrix[maxy][minj]);
          }
       }
        return ans;
    }
};