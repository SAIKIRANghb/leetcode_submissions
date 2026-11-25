// Last updated: 11/25/2026, 3:42:11 PM
// class Solution {
// public:
//     int longestPalindrome(vector<string>& words) {
//         int n = words.size();
//         unordered_set<string>st;
//         unordered_map<string,int>mp;
//         int len = 0;
//         for(int i = 0;i < n;i++){
//             string iTH = words[i];
//             if(iTH[0] == iTH[1]){
//                 mp[iTH]++;
//                 continue;
//             }
//             if(st.find(iTH) != st.end()){
//                 len += 4;
//             }
//             reverse(iTH.begin(),iTH.end());
//             st.insert(iTH);
//         }
//         int oneFreq = 0;
//         for(auto &[key,value] : mp){
//             if(value > 1){
//                 len += 2*(value - value % 2);
//             }else{
//                 oneFreq++;
//             }
//         }
//         cout<<oneFreq;
//         return len + 2 *(oneFreq > 0);
//     }
// };
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int len = 0;
        bool central = false;

        for (string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (mp.count(rev)) {
                len += 4;
                mp[rev]--;
                if(mp[rev] == 0)mp.erase(rev);
            } else {
                mp[word]++;
            }
        }

        for (auto& [word, count] : mp) {
            if (word[0] == word[1]) {
                central = true;
                break;
            }
        }

        if (central) len += 2;

        return len;
    }
};
