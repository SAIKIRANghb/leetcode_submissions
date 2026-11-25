// Last updated: 11/25/2026, 3:40:18 PM
class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int Prev1count = 0;
        long long swaps = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '1')Prev1count++;
            else if(s[i] == '0'){
                swaps += Prev1count;
            }
        }
        return swaps;
    }
};