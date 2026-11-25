// Last updated: 11/25/2026, 3:45:50 PM
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int i = rStart, j = cStart;
        int total = rows * cols;
        ans.push_back({i, j});
        if (total == 1) return ans;

        int step = 1;  // Initial step size
        while (ans.size() < total) {
            // Move in each direction: right, down, left, up

            // Move right
            for (int k = 0; k < step; ++k) {
                ++j;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    ans.push_back({i, j});
                }
            }

            // Move down
            for (int k = 0; k < step; ++k) {
                ++i;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    ans.push_back({i, j});
                }
            }

            ++step;  // Increase step size after completing a right-down move

            // Move left
            for (int k = 0; k < step; ++k) {
                --j;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    ans.push_back({i, j});
                }
            }

            // Move up
            for (int k = 0; k < step; ++k) {
                --i;
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    ans.push_back({i, j});
                }
            }

            ++step;  // Increase step size after completing a left-up move
        }

        return ans;
    }
};
