// Last updated: 11/25/2026, 3:43:51 PM
class Solution {
public:
    void solve(string str, int n, int k, priority_queue<string>& sortedStrings) {
        if (str.length() == n) {
            sortedStrings.push(str);
            if (sortedStrings.size() > k) sortedStrings.pop();
            return;
        }
        for (char c = 'a'; c <= 'c'; c++) {
            if (str.empty() || str.back() != c) { 
                solve(str + c, n, k, sortedStrings);
            }
        }
    }

    string getHappyString(int n, int k) {
        priority_queue<string> sortedStrings;
        solve("", n, k, sortedStrings);
        if (sortedStrings.size() < k) return "";
        return sortedStrings.top();
    }
};
