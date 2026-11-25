// Last updated: 11/25/2026, 3:37:45 PM
class Solution {
public:
    bool hasSameDigits(string s) {
        if(s.size() == 1)return false;
        if(s.size() == 2)return s[0] == s[1];
        while(s.size() > 2){
            int n = s.size();
            string temp = "";
            for(int i = 0;i < n - 1;i++){
                int x = s[i] - '0';
                int y = s[i + 1] - '0';
                temp += to_string((x + y)%10);
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};