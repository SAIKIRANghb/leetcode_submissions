// Last updated: 11/25/2026, 3:39:23 PM
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void helper(int n, string s, int prev) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }
            if(prev != '0')helper(n - 1, s + '0', '0'); // Append '0' and set hasOne to false
            helper(n - 1, s + '1', '1');  // Append '1' and keep hasOne true 
    }

    vector<string> validStrings(int n) {
        helper(n, "", -1);
        return ans;
    }
};
