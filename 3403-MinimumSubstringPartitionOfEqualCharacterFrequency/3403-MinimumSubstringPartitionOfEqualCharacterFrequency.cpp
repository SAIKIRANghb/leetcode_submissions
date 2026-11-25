// Last updated: 11/25/2026, 3:39:44 PM
class Solution {
public:
    int n;
    vector<vector<int>>prefSum;
    vector<int>dp;
    int recSolve(int i,string s){
        if(i == -1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int minAns = n;
        for(int j = i ;j>=0;j--){
            bool flag = true;
            int cnt = 0;
            for(int k=0;k<26;k++){
                int NumOfOccur = prefSum[i][k] - (j-1>=0 ? prefSum[j-1][k] : 0);
                if(cnt!=0 && NumOfOccur!=0 && NumOfOccur != cnt){
                    flag = false;
                    break;
                }
                cnt = max(cnt,NumOfOccur); 
            }
            if(!flag){
                continue;
            }
            minAns = min(minAns,1 + recSolve(j-1,s));
        }
        dp[i] = minAns;
        return dp[i];
    }
    int minimumSubstringsInPartition(string s) {
        n = s.size();
        dp = vector<int>(n+1,-1);
        prefSum = vector<vector<int>>(n+1,vector<int>(26,0));
        prefSum[0][s[0]-'a'] = 1;

        for(int i = 1 ;i<n; i++){
            prefSum[i][s[i]-'a']++;
            for(int j=0;j<26;j++){
                prefSum[i][j] += prefSum[i-1][j];
            }
        }
        return recSolve(n-1,s);
    }
};