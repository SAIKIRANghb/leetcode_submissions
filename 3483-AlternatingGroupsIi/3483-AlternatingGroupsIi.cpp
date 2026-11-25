// Last updated: 11/25/2026, 3:39:08 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int r = 0;
        int n = colors.size();
        int winSize = 0;
        int numGrps = 0;

        while(r < n + k - 1){
            if(colors[r % n] != colors[(r + 1) % n]){
                winSize++;
            }else{
                winSize = 1;
            }
            if(winSize >= k){
                numGrps++;
            }
            r++;
        }
        return numGrps;
    }
};

