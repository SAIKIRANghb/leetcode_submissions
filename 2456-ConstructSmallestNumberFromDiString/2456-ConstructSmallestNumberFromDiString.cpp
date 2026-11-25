// Last updated: 11/25/2026, 3:41:39 PM
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string res;
        for(int currInd = 0,prevInd = 0;currInd <= n;currInd++){
            res += to_string(currInd + 1);
            if(currInd == n || pattern[currInd] == 'I'){
                reverse(res.begin() + prevInd,res.end());
                prevInd = currInd + 1;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     string smallestNumber(string pattern) {
//         int n = pattern.size();
//         string res = "";
//         stack<int>numStack;
//         for(int num = 0;num <= n;num++){
//             numStack.push(num + 1);
//             if(num == n || pattern[num] == 'I'){
//                 while(!numStack.empty()){
//                     res += to_string(numStack.top());
//                     numStack.pop();
//                 }
//             }
//         }
//         return res;
//     }
// };



// class Solution {
// public:
//     string smallestNumber(string pattern) {
//         string ans = "";
//         solve(0,0,pattern,ans);
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
//     private:
//     int solve(int ind,int cnt,string pattern,string &ans){
//         if(ind == pattern.size()){
//             ans += to_string(cnt + 1);
//             return cnt + 1;
//         }
//         if(pattern[ind] == 'I')solve(ind + 1,cnt + 1,pattern,ans);
//         else cnt = solve(ind + 1,cnt,pattern,ans);
//         ans += to_string(cnt + 1);
//         return cnt + 1;
//     }
// };
