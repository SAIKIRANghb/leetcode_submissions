// Last updated: 11/25/2026, 3:43:00 PM
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if(n == 2)return (s1[0] == s2[1] && s1[1] == s2[0]) || (s1 == s2);
        if (n == 1)return s1 == s2;
        if(n != s2.size())return false;
        int cnt = 0;
        char a , b , c , d;
        for(int i = 0;i < n;i++){
            if(s1[i] != s2[i]){
                cnt++;
                if(cnt == 1){a = s1[i];b = s2[i];}
                if(cnt == 2){c = s2[i];d = s1[i];}
                if(cnt == 2 && (a != c || b != d))return false;
                if(cnt > 2){
                    return false;
                }
            }
        }
        if(cnt == 1)return false;
        return true;
    }
};