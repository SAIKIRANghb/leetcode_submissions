// Last updated: 11/25/2026, 3:39:11 PM
#include <string>
using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            // Calculate the index of the kth character after s[i]
            int newIndex = (i + k) % n;
            ans += s[newIndex];
        }
        return ans;
    }
};
