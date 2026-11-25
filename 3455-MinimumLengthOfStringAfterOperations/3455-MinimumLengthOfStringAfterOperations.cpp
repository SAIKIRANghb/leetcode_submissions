// Last updated: 11/25/2026, 3:39:20 PM
class Solution {
public:
    int minimumLength(string s) {
        vector<int>chars(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            chars[s[i] - 'a']++;
        }
        int ans = n;
        for(int i=0;i<26;i++){
            if(chars[i]%2 == 0){
                ans -= ((chars[i]-1) / 2 ) * 2;
                chars[i] = 1;
            }if(chars[i]%2 == 1){
                ans -= ((chars[i]) / 2) * 2;
                chars[i] = 1;
            }
            
        }
        return ans;
    }
};