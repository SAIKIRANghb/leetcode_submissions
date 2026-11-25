// Last updated: 11/25/2026, 3:45:55 PM
//since the problem is finding pairs before some value that match a sum should point you towards Two Sum problem

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n , 0));
        int maxLen = 0;
        for(int curr = 2;curr < n;curr++){
            int start = 0 , end = curr - 1;
            while(start < end){
                if(arr[start] + arr[end] < arr[curr]){
                    start++;
                }else if(arr[start] + arr[end] > arr[curr]){
                    end--;
                }else{
                    dp[end][curr] = 1 + dp[start][end];
                    maxLen = max(maxLen , dp[end][curr]);
                    start++;
                    end--;
                }
            }
        }
        return maxLen > 0 ? maxLen + 2 : 0; 
    }
};


// T.C : O(N^2)
// S.C : O(N^2)
// class Solution {
// public:
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size();
//         int maxLen = 0;
//         vector<vector<int>>dp(n,vector<int>(n,0));
//         unordered_map<int,int>val2ind;
//         for(int curr = 0;curr < n;curr++){
//             val2ind[arr[curr]] = curr;
//             for(int prev = 0;prev < curr;prev++){
//                 int x_2 = arr[curr] - arr[prev];
//                 int prev_ind = (val2ind.count(x_2)) ? val2ind[x_2] : -1;
//                 if(x_2 < arr[prev] && prev_ind >= 0){
//                     dp[prev][curr] = 1 + dp[prev_ind][prev];
//                 }else{
//                     dp[prev][curr] = 2;
//                 }
//                 maxLen = max(maxLen,dp[prev][curr]);
//             }
//         }
//         return maxLen > 2 ? maxLen  : 0;
//     }
// };


// TC : O(N^2 * logM) where  M = largest possible integer in constraints
// S.C : O(N)
// class Solution {
// public:
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size(),maxLen = 0;
//         unordered_map<int,int>mp;

//         for(int i = 0;i < n;i++){
//             mp[arr[i]] = i;
//         }

//         for(int i = 0;i < n - 1;i++){
//             for(int j = i + 1;j < n;j++){
//                 int a_1 = arr[j];
//                 int a_2 = arr[i];
//                 int a0 = a_1 + a_2;
//                 int len = 2;
//                 while(mp.count(a0)){
//                     a_2 = a_1;
//                     a_1 = a0;
//                     a0 = a_1 + a_2;
//                     len++;
//                     if(len >= 3){
//                         maxLen = max(maxLen,len);
//                     }
//                 }
//             }
//         }
//         return maxLen;
//     }
// };
