// Last updated: 11/25/2026, 3:47:45 PM
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int i = -1, j = -1;
//         int x = 0;
//         for(x = 0;x<n;x++){
//             if(nums[x] == 0){
//                 i = x;
//                 j = x;
//                 break;
//             }
//         }
//         if(i == -1)return;

//         while(i < n){
//             while(i < n - 1 && nums[i + 1] != 0){
//                 swap(nums[j],nums[i + 1]);
//                 i++;
//                 j++;
//             }
//             while(i < n - 1 && nums[i + 1] == 0){
//                 i++;
//             }
//         }   
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1, j = -1;
        int x = 0;
        
        // Find the first zero
        for(x = 0; x < n; x++) {
            if(nums[x] == 0) {
                i = x;
                j = x;
                break;
            }
        }
        
        // If no zeros found, return
        if(i == -1) return;

        // Continue from the point where first zero was found
        while(i < n - 1) {
            // Move forward until a non-zero element is found
            while(i < n - 1 && nums[i + 1] == 0) {
                i++;
            }
            
            // If we've reached the end, break
            if(i >= n - 1) break;
            
            // Swap zero with next non-zero element
            swap(nums[j], nums[i + 1]);
            
            // Move pointers
            i++;
            j++;
        }   
    }
};