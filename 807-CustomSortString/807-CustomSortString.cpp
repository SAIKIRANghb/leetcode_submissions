// Last updated: 11/25/2026, 3:46:09 PM
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    string customSortString(string order, string s) {
        // Initialize all ranks to a large number (like 100) 
        // so characters NOT in 'order' naturally go to the end.
        vector<int> rank(26, 100);

        // Fix 1: Loop up to order.length(), not 26, to prevent crashes
        for(int i = 0; i < order.length(); i++) {
            rank[order[i] - 'a'] = i;
        }

        // Convert string to vector of chars
        vector<char> str(s.begin(), s.end());

        // Fix 2: Capture rank by reference [&rank] for better performance
        sort(str.begin(), str.end(), [&rank](char a, char b) {
            return rank[a - 'a'] < rank[b - 'a'];
        });

        // Convert vector back to string cleanly
        return string(str.begin(), str.end());
    }
};


//nimmakay // chutney