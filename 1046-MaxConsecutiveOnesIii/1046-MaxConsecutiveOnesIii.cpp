// Last updated: 11/25/2026, 3:45:11 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int i = 0;
        for(int j = 0;j<n;j++){
            if(nums[j] == 0){
                k--;
            }
            if(k<0)i++;
            if(k < 0 && nums[i - 1] == 0){
                k++;
            }
            maxLen = max(maxLen , j - i + 1);
        }   
        return maxLen;
    }
};















// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i = 0,j = 0;
//         for( j = 0;j<n;j++){
//             if(nums[j] == 0){
//                 k--;
//             }
//             if(k < 0 && nums[i++] == 0){
//                 k++;
//             }   
//         }
//         return j - i;
//     }

// };