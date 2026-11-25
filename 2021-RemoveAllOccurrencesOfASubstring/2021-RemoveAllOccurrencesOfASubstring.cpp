// Last updated: 11/25/2026, 3:42:44 PM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int partLen = part.size();
        for (char ch : s){
            res.push_back(ch);
            if(res.size() >= partLen && res.substr(res.size() - partLen) == part){
                res.erase(res.size() - partLen);
            }
        }
        return res;
    }
};