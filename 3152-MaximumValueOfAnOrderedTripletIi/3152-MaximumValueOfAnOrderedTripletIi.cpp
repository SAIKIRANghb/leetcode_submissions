// Last updated: 11/25/2026, 3:40:26 PM
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 2) return 0;

//         long long max_i = nums[0]; 
//         long long min_j = nums[1]; 

//         long long ans = 0;

//         for (int k = 2; k < n; k++) {
//             ans = max(ans, 1LL * (max_i - min_j) * nums[k]); // Compute the triplet value
            
//             // Update max_i and min_j for the next iteration
//             max_i = max(max_i, 1LL * nums[k - 1]); // max_i should track the max up to index k-1
//             min_j = min(min_j, 1LL * nums[k - 1]) == max_i ? min_j : min(min_j, 1LL * nums[k - 1]); // min_j should track the min up to index k-1
//         }

//         return ans;
//     }
// };

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
        }
        return res;
    }
};
