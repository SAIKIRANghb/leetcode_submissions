// Last updated: 11/25/2026, 3:41:52 PM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxLen = 0;

        // Loop over each bit position from 0 to 31 (for 32-bit integers).
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;

            // Count how many candidates have this bit set.
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }

            // Keep track of the maximum count of set bits at any position.
            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};


// class Solution {
// public:
//     int solve(int i, int AND, unordered_map<string, int>& memo, vector<int>& arr) {
//         // Base case: If we reach the end of the array, return 0 as no more elements can be included.
//         if (i == arr.size()) return 0;

//         // If AND is zero, return 0 because no further elements can keep a non-zero AND.
//         if (AND == 0) return 0;

//         // Create a unique key for the current state.
//         string key = to_string(i) + "_" + to_string(AND);

//         // If the result is already computed for this state, return it from the memo map.
//         if (memo.find(key) != memo.end()) return memo[key];

//         // Option 1: Include the current element in the subset and update the AND.
//         int take = 0;
//         if (AND & arr[i]) {
//             take = 1 + solve(i + 1, AND & arr[i], memo, arr);
//         }

//         // Option 2: Exclude the current element.
//         int notTake = solve(i + 1, AND, memo, arr);

//         // Memoize and return the maximum length obtained from either including or excluding the current element.
//         return memo[key] = max(take, notTake);
//     }

//     int largestCombination(vector<int>& candidates) {
//         unordered_map<string, int> memo;
//         return solve(0, INT_MAX, memo, candidates);
//     }
// };
