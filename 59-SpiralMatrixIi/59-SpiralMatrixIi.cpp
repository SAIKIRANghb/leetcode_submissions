// Last updated: 11/25/2026, 3:49:42 PM
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int count = 1;

        while (left <= right && top <= bottom) {
            // Fill the top row from left to right
            for (int i = left; i <= right; i++) {
                ans[top][i] = count;
                count++;
            }
            top++;

            // Fill the rightmost column from top to bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = count;
                count++;
            }
            right--;

            // Fill the bottom row from right to left (if applicable)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = count;
                    count++;
                }
                bottom--;
            }

            // Fill the leftmost column from bottom to top (if applicable)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = count;
                    count++;
                }
                left++;
            }
        }

        return ans;
    }
};
