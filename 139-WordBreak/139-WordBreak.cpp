// Last updated: 11/25/2026, 3:48:48 PM
//tabulation dp ==> dp[n] depends on dp[n - 1] , dp[n - 2] ...,dp[0] 
// the bool dp[i] says that substring of s(0 -> i) can be formed from dictionary
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n + 1,false);
        unordered_set<string>st;
        for(string str : wordDict){
            st.insert(str);
        }
        dp[0] = true; //base case empty string is always present
        for(int len = 1;len <= n;len++){
            for(int i = 0;i < len;i++){
                if(dp[i] && st.find(s.substr(i , len - i))!= st.end()){
                    dp[len] = true;
                    break;
                } 
            }
        }
        return dp[n];
    }
};



// HashMap memoization

// class Solution {
// public:
//     bool dfs(unordered_map<string,bool>& dp,set<string> &st,string s){
//         if(s == "")return true;
        
//         if(dp.find(s) != dp.end())return dp[s];
        
//         int n = s.size();
        
//         for(int i = 0;i < n ;i++){
//             if(st.find(s.substr(0,i + 1)) != st.end() && dfs(dp,st,s.substr(i + 1,n - i))){
//                 return dp[s] = true;
//             }
//         }
//         return dp[s] = false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_map<string,bool> dp;
//         set<string> st;
//         for(string str : wordDict){
//             st.insert(str);
//         }
//         return dfs(dp,st,s);
//     }
// };