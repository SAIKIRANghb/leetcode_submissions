// Last updated: 11/25/2026, 3:48:06 PM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_map<char,char>used;
        int n = s.size();
        if(n != t.size())return false;

        for(int i = 0;i<n;i++){
            if(mp.find(s[i]) != mp.end()){
                if(mp[s[i]] != t[i])return false;
            }else{
                if(used.find(t[i]) != used.end()){
                    return false;
                }else {
                    mp[s[i]] = t[i];
                    used[t[i]] = s[i];
                }
            }
        }
        return true;
    }
};