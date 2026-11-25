// Last updated: 11/25/2026, 3:39:42 PM
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int>mpp;
        int n = t.size(),sum = 0;
        for(int i = 0 ;i<n ;i++){
            mpp[t[i]] = i ;
        }
        for(int i = 0 ;i<n;i++){
            int ind = mpp[s[i]];
            sum += abs(i-ind);
        }
        return sum;
    }
};