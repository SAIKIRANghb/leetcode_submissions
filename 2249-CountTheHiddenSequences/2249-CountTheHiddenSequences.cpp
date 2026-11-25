// Last updated: 11/25/2026, 3:42:09 PM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long currDiff = 0;
        long maxDiff = 0,minDiff = 0;
        for(int i = 0;i < n;i++){
            currDiff += differences[i];
            maxDiff = max(maxDiff,currDiff); //finds max h[i + k] - h[0]
            minDiff = min(minDiff,currDiff); //finds min h[i + k] - h[0]  
            //however h[0] will get cancelled in further calculations
        }

        long validStart = lower - minDiff;
        long validEnd = upper - maxDiff;

        if(validStart > validEnd)return 0;

        return validEnd - validStart + 1;
    }
};