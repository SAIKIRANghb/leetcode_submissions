// Last updated: 11/25/2026, 3:39:31 PM
// class Solution {
// public:
//     vector<int> queryResults(int limit, vector<vector<int>>& queries) {
//         vector<int>mp(limit + 1);
//         int qn = queries.size();
//         vector<int>ans(qn,-1);
//         unordered_map<int,int>clr;
//         for(int i = 0;i < qn;i++){
//             int x = queries[i][0];
//             int y = queries[i][1];
//             if(mp[x] != 0){
//                 int prevClr = mp[x];
//                 mp[x] = y;
//                 clr[prevClr]--;
//                 if(clr[prevClr] == 0)clr.erase(prevClr);
//                 clr[y]++;
//                 ans[i] = clr.size();
//             }else{
//                 mp[x] = y;
//                 clr[y]++;
//                 ans[i] = clr.size();
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp; // Instead of vector<int> mp(limit + 1)
        unordered_map<int, int> clr;
        int qn = queries.size();
        vector<int> ans(qn, -1);

        for (int i = 0; i < qn; i++) {
            int x = queries[i][0];
            int y = queries[i][1];

            auto it = mp.find(x);
            if (it != mp.end()) {
                int prevClr = it->second;
                it->second = y;
                if (--clr[prevClr] == 0) clr.erase(prevClr);
                clr[y]++;
            } else {
                mp[x] = y;
                clr[y]++;
            }
            ans[i] = clr.size();
        }
        return ans;
    }
};
