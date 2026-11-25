// Last updated: 11/25/2026, 3:50:23 PM
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n , vector<bool>(n, false));
        int maxLen = 1;
        int startInd = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])){
                    dp[j][i] = true;
                    if(maxLen < i - j + 1){
                        maxLen = i - j + 1;
                        startInd = j;
                    }
                }
            }
        }
        return s.substr(startInd ,maxLen);
    }
};



// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();

//         vector<vector<bool>>dp(n,vector<bool>(n,0));
//         int startInd = 0;
//         int maxLen = 1;
//         for(int i = 0;i<n;i++){
//             dp[i][i] = true;
//             for(int j = 0 ; j < i ;j++){
//                 if(s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])){
//                     dp[j][i] = true;
//                     if(i - j + 1 > maxLen){
//                         maxLen = i - j + 1;
//                         startInd = j;
//                     }
//                 }
//             }
//         }
//         return s.substr(startInd,maxLen);   
//     }
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         vector<vector<int>>dp(n,vector<int>(n,0));
//         int maxLen = 0;
//         int startInd = -1;
//         for(int diff = 0;diff <= n - 1;diff++){
//             for(int i = 0,j = i + diff;j < n;j++,i++){
//                 if(i == j){
//                     dp[i][j] = 1;
//                 }else if(diff == 1){
//                     dp[i][j] = (s[i] == s[j]) ? 2 : 0;
//                 }else{
//                     dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1] > 0) ? dp[i + 1][j - 1] + 2 : 0;
//                 }
//                 if(dp[i][j] > 0){
//                     if(maxLen < j - i + 1){
//                         maxLen = max(maxLen,j - i + 1);
//                         startInd = i;
//                     }
//                 }
//             }
//         }
//         return s.substr(startInd , maxLen);
//     }
// };


// class Solution {
// public:
//     unordered_map<int,unordered_map<int,int>>dp;
//     // vector<vector<int>>dp;
//     bool solve(string s,int l , int r){
//         if(l >= r){
//             return 1;
//         }
//         if(dp.find(l) != dp.end() && dp[l].find(r) != dp[l].end())return dp[l][r];
//         // if(dp[l][r] != -1)return dp[l][r];
//         if(s[l] == s[r]){
//            return dp[l][r] = solve(s,l + 1,r - 1);
//         }
//         return dp[l][r] = 0;
//     }
//     string longestPalindrome(string s) {
//         int n = s.size();
//         int maxLen = INT_MIN;
//         int startInd = -1;
//         // dp = vector<vector<int>>(n,vector<int>(n,-1));
//         for(int i = 0;i<n;i++){
//             for(int j = i;j<n;j++){
//                 if(solve(s,i,j)){
//                     if(j - i + 1 > maxLen){
//                         maxLen = j - i + 1;
//                         startInd = i;
//                     }
//                 }
//             }
//         }
//         return s.substr(startInd ,maxLen);
//     }
// };