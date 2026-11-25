// Last updated: 11/25/2026, 3:40:38 PM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x = nums[0] , cnt = 0,xCnt = 0,n = nums.size();

        for(int i = 0;i < n;i++){
            if(nums[i] == x){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                x = nums[i];
                cnt = 1;
            }
        }

        for(int i = 0;i < n;i++){
            if(x == nums[i]){
                xCnt++;
            }
        }
        cnt = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] == x){
                cnt++;
            }
            int remCnt = xCnt - cnt;
            if(cnt * 2 > i + 1 && remCnt * 2 > n - i - 1){
                return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int minimumIndex(vector<int>& nums) {
//         unordered_map<int,int>firstMp;
//         unordered_map<int,int>secondMp;
//         int n = nums.size();
//         for(int i = 0;i < n;i++){
//             secondMp[nums[i]]++;
//         }
//         for(int i = 0;i < n;i++){
//             firstMp[nums[i]]++;
//             secondMp[nums[i]]--;
//             if(firstMp[nums[i]] * 2 > i + 1 && secondMp[nums[i]] * 2 > n - i - 1){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };