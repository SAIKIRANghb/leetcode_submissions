// Last updated: 11/25/2026, 3:41:38 PM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int l = 0, r = 0;
        int b = 0;
        int w = 0;
        int minOps = INT_MAX;
        while(r < n){
            if(blocks[r] == 'W'){
                w++;
            }else{
                b++;
            }
            if(r - l + 1 == k){
                int reqb = k - b;
                minOps = min(reqb,minOps);
                if(blocks[l] == 'W')w--;
                else b--;
                l++;
            } 
            r++;
        }
        return minOps;
    }
};