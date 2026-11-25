// Last updated: 11/25/2026, 3:47:19 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>mp(26,0);
        int maxLen = 0;
        int maxFreq = 0;
        int i = 0;
        for(int j = 0;j<n;j++){
            mp[s[j] - 'A']++;
            maxFreq = max(maxFreq,mp[s[j] - 'A']);
            if((j - i + 1) - maxFreq > k){
                mp[s[i] - 'A']--;
                i++;
            }
            maxLen = max(maxLen,j - i + 1);
        }
        return maxLen;
    }
};













// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         int l = 0,r = 0;

//         vector<int>mp(26,0);
//         int maxLen = 0;
//         int maxFreq = 0;

//         while(r < n){
//             mp[s[r] - 'A']++;
//             maxFreq = max(maxFreq , mp[s[r] - 'A']);
//             while((r - l + 1) - maxFreq > k){
//                 mp[s[l] - 'A']--;
//                 l++;
//             }
//             maxLen = max(maxLen , r - l + 1);
//             r++;
//         }
//         return maxLen;
//     }
// };