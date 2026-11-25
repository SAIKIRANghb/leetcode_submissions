// Last updated: 11/25/2026, 3:40:27 PM
// class Solution {
// public:
//     vector<vector<int>>dp;
//     vector<int>prevArr;
//     int maxInd;
//     int solve(int ind , int prev,vector<string>& words, vector<int>& groups){
//         int n = groups.size();
//         if(ind == n)return 0;
//         if(dp[ind][prev + 1] != -1)return dp[ind][prev + 1];
//         if(prev == -1){
//             int take = 1 + solve(ind + 1,ind,words,groups);
//             int notTake = solve(ind + 1,prev,words,groups);
//             if(take > notTake){
//                 prevArr[ind + 1] = ind;
//                 maxInd = ind;
//             }else{
//                 prevArr[ind + 1] = prev + 1;
//                 maxInd = prev + 1;
//             }
//             return dp[ind][prev + 1] = max(take,notTake);
//         }else{
//             int take = 0;
//             if(groups[ind] != groups[prev]){
//                 take = 1 + solve(ind + 1,ind,words,groups);
//             }
//             int notTake = solve(ind + 1,prev,words,groups);
//             if(take > notTake){
//                 prevArr[ind + 1] = ind;
//                 maxInd = ind;
//             }else{
//                 prevArr[ind + 1] = prev + 1;
//                 maxInd = prev + 1;
//             }
//             return dp[ind][prev + 1] = max(take,notTake);
//         }
//     }
//     vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
//         int n = words.size();
//         prevArr = vector<int>(n + 1,-1);
//         dp = vector<vector<int>>(n,vector<int>(n + 1,-1));
//         maxInd = 0;
//         cout<<solve(0,-1,words,groups);
//         int ptr = maxInd;
//         vector<string>ans;
//         while(ptr != 0){
//             ans.push_back(words[ptr]);
//             ptr = prevArr[ptr];
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> parent;

    int solve(int ind, int prev, vector<int>& groups, int n) {
        if (ind == n) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notTake = solve(ind + 1, prev, groups, n);
        int take = 0;
        if (prev == -1 || groups[ind] != groups[prev]) {
            take = 1 + solve(ind + 1, ind, groups, n);
        }

        // Store decision in parent table
        if (take > notTake) {
            parent[ind][prev + 1] = ind;
            return dp[ind][prev + 1] = take;
        } else {
            parent[ind][prev + 1] = prev;
            return dp[ind][prev + 1] = notTake;
        }
    }

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
        parent = vector<vector<int>>(n, vector<int>(n + 1, -1));

        solve(0, -1, groups, n);

        // Trace the result
        vector<string> result;
        int ind = 0, prev = -1;

        while (ind < n) {
            int nextPrev = parent[ind][prev + 1];
            if (nextPrev == ind) {
                result.push_back(words[ind]);
                prev = ind;
            }
            ind++;
        }

        return result;
    }
};
