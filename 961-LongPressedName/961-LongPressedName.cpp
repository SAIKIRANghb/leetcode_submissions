// Last updated: 11/25/2026, 3:45:39 PM
class Solution {
public:
    bool isLongPressedName(string s, string t) {
        int i=0,j=0;
        int n1=s.size();
        int n2=t.size();
        while(i<=n1 && j <=n2){
            if(s[i]==t[j]){
                i++;j++;
            }
            else if(s[i]!=t[j] && i>0 && s[i-1] == t[j]){
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};