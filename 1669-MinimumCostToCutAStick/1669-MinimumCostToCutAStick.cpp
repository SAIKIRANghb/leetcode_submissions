// Last updated: 11/25/2026, 3:43:33 PM
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c + 2,vector<int>(c + 2, 0));

        for(int i = c;i >= 1;i--){
            for(int j = 1;j <= c;j++){
                if(i > j)continue;
                int mini = INT_MAX;
                for(int ind = i;ind <= j;ind++){
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};

// class Solution {
// public:
//     int findMinCost(int i, int j, vector<int>&cuts,vector<vector<int>>&dp){
//         if(i > j)return 0;

//         if(dp[i][j] != -1)return dp[i][j];

//         int mini = INT_MAX;
//         for(int ind = i;ind <= j;ind++){
//             int ans = (cuts[j + 1] - cuts[i - 1]) + findMinCost(i , ind - 1,cuts,dp) + findMinCost(ind + 1,j,cuts,dp);
//             mini = min(mini,ans);
//         }
//         return dp[i][j] = mini;
//     }
//     int minCost(int n, vector<int>& cuts) {
//         cuts.push_back(n);
//         cuts.insert(cuts.begin(),0);
//         int c = cuts.size();
//         vector<vector<int>>dp(c + 1,vector<int>(c + 1,-1));
//         sort(cuts.begin(),cuts.end());
//         return findMinCost(1,c - 2,cuts,dp);
//     }
// };
