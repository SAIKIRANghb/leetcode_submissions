// Last updated: 11/25/2026, 3:44:56 PM
//Optimal approach:

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int strln1 = str1.length();
        int strln2 = str2.length();
        vector<vector<int>>dp(strln1 + 1,vector<int>(strln2 + 1,0));
        for(int i = 0;i <= strln1;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j <= strln2;j++){
            dp[0][j] = j;
        }

        for(int i = 1;i <= strln1;i++){
            for(int j = 1;j <= strln2;j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = 1 + min(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        int i = strln1, j = strln2;
        string ans = "";
        while(i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                ans += str1[i - 1];
                i--;
                j--;
            }else if(dp[i - 1][j] < dp[i][j - 1]){
                ans += str1[i - 1];
                i--;
            }else{
                ans += str2[j - 1];
                j--;
            }
        }
        while(i > 0){
            ans += str1[i - 1];
            i--;
        }
        while(j > 0){
            ans += str2[j - 1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



// Loops for n*m times and O(n + m) for string concatenation => time complexity = O(n.m.(n + m))
// vector of strings length -> m and each entry can be (n + m) long -> space = O(m.(n + m))
// In C++, storing full strings in the table is much more memory-intensive than in Java and Python, leading to a Memory Limit Exceeded (MLE) error

// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         int str1Ln = str1.length();
//         int str2Ln = str2.length();

//         //Initialize the first row (when str1 is empty , the supersequence is str2's prefix)
//         vector<string>prevRow(str2Ln + 1);
//         for(int col = 0; col <= str2Ln;col++){
//             prevRow[col] = str2.substr(0,col);
//         }

//         for(int row = 1;row <= str1Ln;row++){
//             // Initialize the first column (when str2 is empty, the supersequence is str1's prefix)
//             vector<string>currRow(str2Ln + 1);
//             currRow[0] = str1.substr(0,row);

//             for(int col = 1;col <= str2Ln;col++){
//                 if(str1[row - 1] == str2[col - 1]){
//                     currRow[col] = prevRow[col - 1] + str1[row - 1];
//                 }else{
//                     string pickS1 = prevRow[col];
//                     string pickS2 = currRow[col - 1];
//                     currRow[col] = (pickS1.length() < pickS2.length()) ? pickS1 + str1[row - 1] : pickS2 + str2[col - 1];
//                 }
//             }
//             prevRow = currRow;
//         }
//         return prevRow[str2Ln];
//     }
// };


//*we have O(n⋅m) unique subproblems,each subproblem we perform string operations, 
//including concatenation (+) and substring, which take O(n+m) time in the worst case.
//*The memoKey creation using string concatenation also takes O(n+m) time.

//=>the total Time Complexity is O(n⋅m⋅(n+m))

//*Hash map stores results for O(n⋅m) subproblems
// Each stored result can be up to O(n+m) in the worst case and recursion stack can grow up to O(n) or O(m)

//=>total Space Complexity is O(n⋅m⋅(n+m))

// MLE only
// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         unordered_map<string,string>memo;
//         return helper(str1,str2,memo);
//     }
//     string helper(string str1,string str2,unordered_map<string,string>&memo){
//         string memoKey = str1 + "_" + str2;
//         if(memo.find(memoKey) != memo.end()){
//             return memo[memoKey];
//         }

//         if(str1.empty() && str2.empty()){
//             return "";
//         }
//         if(str1.empty())return str2;
//         if(str2.empty())return str1;

//         if(str1[0] == str2[0]){
//             return memo[memoKey] = str1[0] + helper(str1.substr(1),str2.substr(1),memo);
//         }
//         string pickStr1 = str1[0] + helper(str1.substr(1),str2,memo);
//         string pickStr2 = str2[0] + helper(str1,str2.substr(1),memo);
//         return memo[memoKey] = (pickStr1.length() < pickStr2.length()) ? pickStr1 : pickStr2;
//     }
// };


// TC : 2^(m + n)
// SC : (m + n) ^ 2
// Gives TLE and MLE

// class Solution {
// public:
//     string shortestCommonSupersequence(string str1, string str2) {
//         if(str1.empty() & str2.empty())return "";
//         if(str1.empty())return str2;
//         if(str2.empty())return str1;

//         if(str1[0] == str2[0]){
//             return str1[0] + shortestCommonSupersequence(str1.substr(1),str2.substr(1));
//         }
//         else{
//             string pickStr1 = str1[0] + shortestCommonSupersequence(str1.substr(1),str2);
//             string pickStr2 = str2[0] + shortestCommonSupersequence(str1,str2.substr(1));
//             return (pickStr1.length() < pickStr2.length()) ? pickStr1 : pickStr2;
//         }
//     }
// };
