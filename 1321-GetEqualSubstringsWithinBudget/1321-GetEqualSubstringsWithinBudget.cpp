// Last updated: 11/25/2026, 3:44:25 PM
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i = 0,j = 0;
        int cost = 0;
        int maxLen = 0;
        while(i <= j && j < n){
            cost += abs(s[j] - t[j]);
            if(cost > maxCost){
                cost -= abs(s[i] - t[i]);
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};