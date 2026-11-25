// Last updated: 11/25/2026, 3:38:48 PM
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cons_count = 0;
        vector<int>ans(n - (k - 1),-1);
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i - 1] + 1 == nums[i]){
                cons_count++;
            }else{
                cons_count = 1;
            }
            if(cons_count >= k){
                ans[i - (k - 1)] = nums[i];
            }
        }
        return ans;
    }
};





// #include <vector>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n < k) return {};  // Handle edge case where k is larger than the array size

//         vector<int> ans(n - k + 1, -1);
        
//         for (int start = 0; start <= n - k; ++start) {
//             bool isConsecutiveSorted = true;
//             int maxNum = nums[start];  // Initialize maxNum to the first element in the current window
            
//             // Check if the subarray nums[start..start+k-1] is consecutive and sorted
//             for (int i = start; i < start + k - 1; ++i) {
//                 if (nums[i] + 1 != nums[i + 1]) {
//                     isConsecutiveSorted = false;
//                     break;
//                 }
//                 maxNum = max(maxNum, nums[i + 1]);
//             }
            
//             if (isConsecutiveSorted) {
//                 ans[start] = maxNum;
//             }
//         }
        
//         return ans;
//     }
// };

