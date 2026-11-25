// Last updated: 11/25/2026, 3:39:21 PM
class Solution {
public:
    // long long solve(vector<int>& diff, int left, int right) {
    //     if (left > right) return 0;

    //     // Find the minimum non-zero value in the current range
    //     int minNum = INT_MAX;
    //     for (int i = left; i <= right; ++i) {
    //         if (diff[i] != 0) {
    //             minNum = min(minNum, diff[i]);
    //         }
    //     }
        
    //     // If no non-zero values are found, return 0
    //     if (minNum == INT_MAX) return 0;

    //     // Apply the minimum value to all elements in the range
    //     for (int i = left; i <= right; ++i) {
    //         if (diff[i] != 0) {
    //             diff[i] -= minNum;
    //         }
    //     }

    //     // Count the number of operations
    //     long long operations = minNum;

    //     // Recursively solve for remaining subarrays
    //     int i = left;
    //     while (i <= right) {
    //         if (diff[i] != 0) {
    //             int j = i;
    //             while (j <= right && diff[j] != 0) {
    //                 ++j;
    //             }
    //             // Solve the subarray from i to j-1
    //             operations += solve(diff, i, j - 1);
    //             i = j; // Move to the next subarray
    //         } else {
    //             ++i;
    //         }
    //     }

    //     return operations;
    // }
    long long solve(vector<int>& diff, int left, int right) {
        int n = diff.size();
        int prev = 0, curr = diff[0];
        long long ops = 0;
        for(int i = 0;i<n;i++){
            curr = diff[i];
            if(prev < 0 && curr > 0 || prev > 0 && curr < 0){
                ops += abs(curr);
            }
            else if(abs(prev) <= abs(curr)){
                ops += abs(curr - prev);
            }

            prev = diff[i];
        }
        return ops;
    }
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n);
        
        // Compute the difference array
        for (int i = 0; i < n; ++i) {
            diff[i] = target[i] - nums[i];
        }
        // Solve the problem and return the result
        return solve(diff, 0, n - 1);
    }
};
