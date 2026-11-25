// Last updated: 11/25/2026, 3:46:48 PM
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int rMax = -1e5,rMin = 1e5;
        int dis = INT_MIN;
        for(int i = 0;i<m;i++){
            int array0 = arrays[i][0];
            int arrayn = arrays[i].back();
            dis = max({dis,rMax - array0,arrayn-rMin});
            rMax = max(rMax,arrayn);
            rMin = min(rMin,array0);
        }
        return dis;
    }
};