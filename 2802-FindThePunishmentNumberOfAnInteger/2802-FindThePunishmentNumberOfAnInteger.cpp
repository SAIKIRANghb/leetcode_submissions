// Last updated: 11/25/2026, 3:40:48 PM
class Solution {
public:
    bool canPartition(int num,int target){
        if(target < 0 || num < target)return false;

        if(num == target)return true;

        return canPartition(num/10,target - num % 10) || canPartition(num/100,target - num % 100) || canPartition(num/1000,target - num % 1000);
    }
    int punishmentNumber(int n) {
        int punishmentNum = 0;

        for(int currNum = 1;currNum <= n;currNum++){
            int sq = currNum * currNum;
            if(canPartition(sq,currNum)){
                punishmentNum += sq;
            }
        }
        return punishmentNum;
    }
};
// class Solution {
// public:
//     bool canPartition(string num,int target){
//         if(num == "" && target == 0){
//             return true;
//         }
//         if(target < 0)return false;

//         for(int i = 0;i < num.size();i++){
//             string left = num.substr(0,i + 1);
//             string right = num.substr(i + 1);
//             int leftNum = stoi(left);
//             if(canPartition(right,target - leftNum)){
//                 return true;
//             }
//         }
//         return false;
//     }
//     int punishmentNumber(int n) {
//         int punishNum = 0;
//         for(int i = 1; i <= n;i++){
//             int sq = i * i;
//             string num = to_string(sq);
//             if(canPartition(num,i)){
//                 punishNum += sq;
//             }
//         }
//         return punishNum;
//     }
// };


// class Solution {
// public:
//     bool findPartitions(int ind , int sum, string num,int target,vector<vector<int>>&dp){
//         int n = num.size();
//         if(ind == n){
//             if(sum == target)return true;
//             else return false;
//         }
//         if(sum > target)return false; //pruning
//         if(dp[ind][sum] != -1)return dp[ind][sum]; //memoized values

//         bool isFound = false;
//         for(int i = ind;i < n;i++){
//             string curr = num.substr(ind,i - ind + 1);
//             int val = stoi(curr);
//             isFound = isFound || findPartitions(i + 1,sum + val,num,target,dp);
//             if(isFound)return true;
//         }
//         return dp[ind][sum] = isFound;
//     }
//     int punishmentNumber(int n) {
//         int ans = 0;

//         for(int i = 1;i <= n;i++){
//             int isq = i * i;
//             string num = to_string(isq);
//             vector<vector<int>>dp(num.size(),vector<int>(i + 1, -1));

//             if(findPartitions(0,0,num,i,dp)) ans += isq;

//         }
//         return ans;
//     }
// };