// Last updated: 11/25/2026, 3:50:03 PM

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         int ex = 0;
//         for(int i = n - 1;i>= 1;i--){
//             if(nums[i - 1] < nums[i]){
//                 ex = i;
//                 break;
//             }
//         }
//         auto it = lower_bound(nums.rbegin(),nums.rend() + ex + 1,nums[ex]);
//         int index = it - nums.begin();
//         swap(nums[ex],nums[index]);
//         sort(nums.begin() + ex + 2,nums.end());
//     }
// };
#include <vector>
#include <algorithm> // for std::lower_bound and std::sort
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ex = -1;

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                ex = i;
                break;
            }
        }

        if (ex == -1) {
            // If no such element exists, the array is in descending order.
            // Simply reverse it to get the smallest permutation.
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element greater than nums[ex] in the suffix
        auto it = upper_bound(nums.rbegin(), nums.rbegin() + (n - ex - 1), nums[ex]);

        // Convert reverse iterator to normal index
        int index = (nums.rend() - it) - 1;

        // Step 3: Swap the two elements
        swap(nums[ex], nums[index]);

        // Step 4: Sort the elements after the swapped position to get the next permutation
        sort(nums.begin() + ex + 1, nums.end());
    }
};
