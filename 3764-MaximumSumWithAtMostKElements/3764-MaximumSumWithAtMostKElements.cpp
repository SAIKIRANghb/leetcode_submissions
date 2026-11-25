// Last updated: 11/25/2026, 3:37:48 PM
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        
        // Sort each row in descending order to pick the largest elements first
        for (int i = 0; i < n; i++) {
            sort(grid[i].rbegin(), grid[i].rend());
        }

        // Min heap to keep track of the top-k elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push up to limits[i] elements from each row into the priority queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < limits[i] && j < grid[i].size(); j++) {
                pq.push(grid[i][j]);
                if (pq.size() > k) {
                    pq.pop(); // Remove smallest element to keep only the largest k elements
                }
            }
        }

        // Compute the final sum
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
