// Last updated: 11/25/2026, 3:42:43 PM
class Solution {
public:
    vector<vector<int>>dp;
    const int M = 1e9 + 7;
    vector<string>columnStates;
    void generateColumnStates(string curr,char prevChar,int l,int m){
        if(l == m){
            columnStates.push_back(curr);
            return;
        }

        for(char ch : {'R','G','B'}){
            if(ch == prevChar)continue; 

            generateColumnStates(curr + ch,ch,l + 1,m);
        }
    }
    int solve(int remainCols,int prevInd,int m){
        if(remainCols == 0)return 1;

        int ways = 0;

        if(dp[remainCols][prevInd] != -1)return dp[remainCols][prevInd];

        string prevState = columnStates[prevInd];

        for(int i = 0;i < columnStates.size();i++){
            if(i == prevInd)continue;

            string currState = columnStates[i];
            bool valid = true;

            for(int j = 0;j < m;j++){
                if(prevState[j] == currState[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(remainCols - 1,i,m)) % M;
            }
        }
        return dp[remainCols][prevInd] = ways;
    }
    int colorTheGrid(int m, int n) {
        generateColumnStates("",'#',0,m);
        int totalStates = columnStates.size();

        dp = vector<vector<int>>(n + 1,vector<int>(totalStates + 1,-1));

        int res = 0;

        for(int i = 0;i < totalStates;i++){
            res = (res + solve(n - 1,i,m)) % M;
        }
        return res;
    }
};