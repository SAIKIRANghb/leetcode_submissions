// Last updated: 11/25/2026, 3:49:37 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int low = 0,high = m*n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int x = (mid ) / n, y = (mid) % n;
            if(matrix[x][y] == target){
                return true;
            } 
            if(matrix[x][y] < target){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return false;
    }
};