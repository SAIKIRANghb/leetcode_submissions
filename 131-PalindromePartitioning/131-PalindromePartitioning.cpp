// Last updated: 11/25/2026, 3:48:55 PM
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> LOfS;
    int n;

    bool isPalindrome(string s, int start, int end, vector<vector<bool>>& mp) {
        for (int i = 0; i <= (end - start) / 2; i++) {
            if (s[start + i] != s[end - i]) {
                mp[start][end] = false;
                return false;
            }
        }
        mp[start][end] = true;
        return true;
    }

    void PP(string s, int start, vector<vector<bool>>& mp) {
        if (start == n) {
            ans.push_back(LOfS);
            return;
        }
        for (int i = start; i < n; i++) {
            if (mp[start][i] || isPalindrome(s, start, i, mp)) {
                LOfS.push_back(s.substr(start, i - start + 1));
                PP(s, i + 1, mp);
                LOfS.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<bool>> mp(n, vector<bool>(n, false));
        PP(s, 0, mp);
        return ans;
    }
};
