// Last updated: 11/25/2026, 3:42:58 PM
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> mp(n+1,0);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u]++;
            mp[v]++;
            if(mp[u] == n - 1)return u;
            if(mp[v] == n - 1)return v;
        }
        return -1;
    }
};