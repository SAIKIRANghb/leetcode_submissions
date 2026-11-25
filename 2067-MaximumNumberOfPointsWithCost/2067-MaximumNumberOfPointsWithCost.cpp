// Last updated: 11/25/2026, 3:42:35 PM
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int RowSize = points.size();
        int ColSize = points[0].size();  // Use the correct column size
        vector<long long> row(points[0].begin(), points[0].end());

        for (int r = 1; r < RowSize; r++) {
            vector<long long> nextRow(points[r].begin(), points[r].end());

            vector<long long> left(ColSize, 0);
            vector<long long> right(ColSize, 0);

            left[0] = row[0];
            for (int c = 1; c < ColSize; c++) {
                left[c] = max(row[c], left[c - 1] - 1);
            }

            right[ColSize - 1] = row[ColSize - 1];
            for (int c = ColSize - 2; c >= 0; c--) {
                right[c] = max(row[c], right[c + 1] - 1);  // Use right[c+1] here
            }

            for (int c = 0; c < ColSize; c++) {
                nextRow[c] += max(left[c], right[c]);
            }

            row = nextRow;
        }

        return *max_element(row.begin(), row.end());
    }
};
