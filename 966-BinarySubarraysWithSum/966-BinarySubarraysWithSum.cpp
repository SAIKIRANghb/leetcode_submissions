// Last updated: 11/25/2026, 3:45:37 PM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int prefixZeros = 0;
        int i = 0;
        int sum = 0;
        int ans = 0;
        for(int j = 0;j < n;j++){
            sum += nums[j];

            while((sum > goal || nums[i] == 0) && i < j){
                if(nums[i] == 0){
                    prefixZeros++;
                }else{
                    prefixZeros = 0;
                }
                sum -= nums[i];
                i++;
            }

            if(sum == goal){
                ans += 1 + prefixZeros;
            }
        }
        return ans;
    }
};

















// class Solution {
// public:
//     int Atmostgoal(vector<int>& nums,int goal){
//         int n = nums.size();
//         int sum = 0;
//         int ans = 0;
//         int j = 0;
//         for(int i = 0;i<n;i++){
//             sum += nums[i];

//             while(j <= i && sum > goal){
//                 sum -= nums[j];
//                 j++;
//             }
//             ans += i - j + 1;
//         }
//         return ans;
//     }
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         return Atmostgoal(nums,goal) - Atmostgoal(nums,goal - 1);
//     }
// };