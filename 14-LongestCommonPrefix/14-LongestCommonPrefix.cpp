// Last updated: 11/25/2026, 3:50:16 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];
        int n = strs.size();
        if(n < 2)return strs[0];
        int i = 1;
        while(lcp != "" && i < n){
            string temp = strs[i];
            int tn = temp.size();
            int ln = lcp.size();

            int sze = 0;

            while((sze < tn && sze < ln) && (temp[sze] == lcp[sze])){
                sze++;
            }
            lcp = lcp.substr(0,sze);
            i++;
        }
        return lcp;
    }
};