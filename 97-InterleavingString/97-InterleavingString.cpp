// Last updated: 11/25/2026, 3:49:19 PM
class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i,int j,int k,string &s1,string &s2,string &target){
        int nt = target.size(),n1 = s1.size(),n2 = s2.size();

        // if remaining i len + remaining j len < remainging target not possible to reach target
        if((n1 - i) + (n2 - j) < (nt - k))return false; 
        
        if(k == nt && i == n1  && j == n2){
            return true; //completed the both s1 and s2 strings and nt reached ans = true
        }

        if(dp[i][j] != -1)return dp[i][j];

        bool takeI = false, takeJ = false;

        if(i < n1 && s1[i] == target[k]){
            takeI = solve(i + 1,j,k + 1,s1,s2,target);
        }
        if(j < n2 && s2[j] == target[k]){
            takeJ = solve(i,j + 1,k + 1,s1,s2,target);
        }
        return dp[i][j] = takeI || takeJ;
    }

    bool solveTab(string s1, string s2, string target){
        int n1 = s1.size() , n2 = s2.size(),nt = target.size();
        if(n1 + n2 != nt)return false;
        vector<vector<bool>>dp = vector<vector<bool>>(n1 + 1,vector<bool>(n2 + 1,false));
        dp[0][0] = true;
    //i , j both should start from 0 as the pairs (0,y) and (x,0) are possible
        for(int i = 0;i <= n1;i++){
            for(int j = 0;j <= n2;j++){
                int k = (i + j - 1); //for sure
                if(i > 0 && s1[i - 1] == target[k] && dp[i - 1][j])dp[i][j] = true;
                if(j > 0 && s2[j - 1] == target[k] && dp[i][j - 1])dp[i][j] = true;
            }
        }
        return dp[n1][n2];
    }

    bool isInterleave(string s1, string s2, string s3) {
        // int n1 = s1.size() , n2 = s2.size();
        // dp = vector<vector<int>>(n1 + 1,vector<int>(n2 + 1,-1));
        // return solve(0,0,0,s1,s2,s3);
        return solveTab(s1,s2,s3);
    }
};

//should not compare with any K , because when you are at i , j state the target string should be at (i + j) state, comparing with K's other than K = (i + j) will lead to wrong ans.

// bool solveTab(string s1, string s2, string target){
//     int n1 = s1.size() , n2 = s2.size(),nt = target.size();
//     if(n1 + n2 != nt)return false;
//     if(n1 + n2 == 1)return s1 == target || s2 == target;
//     vector<vector<bool>>dp = vector<vector<bool>>(n1 + 1,vector<bool>(n2 + 1,false));
//     dp[0][0] = true;
//     for(int k = 0;k < nt;k++){
//         for(int i = 0;i <= n1;i++){
//             for(int j = 0;j <= n2;j++){
//                 if(i > 0 && s1[i - 1] == target[k] && dp[i - 1][j])dp[i][j] = true;
//                 if(j > 0 && s2[j - 1] == target[k] && dp[i][j - 1])dp[i][j] = true;
//             }
//         }
//     }
//     return dp[n1][n2];
// }