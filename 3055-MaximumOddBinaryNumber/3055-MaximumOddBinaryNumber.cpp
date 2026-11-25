// Last updated: 11/25/2026, 3:40:30 PM
#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (j >= 0) {
            if (s[j] == '1') {
                char t = s[j];
                s[j] = s[n - 1];
                s[n - 1] = t;
                break;
            }
            j--;
        }

        j = n - 2;
        while (i < j) {
            if (s[i] == '0' && s[j] == '1') {
                char t = s[j];
                s[j] = s[i];
                s[i] = t;
                i++;j--;
            } else if (s[i]=='1' && s[j]=='0') {
                i++;
                j--;
            } else if(s[i]=='1' && s[j]=='1'){
                i++;
            }else{
                j--;
            }
        }

        return s;
    }
};
