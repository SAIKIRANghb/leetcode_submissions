// Last updated: 11/25/2026, 3:50:21 PM
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int i = 0;
        // Ignore leading whitespace
        while (i < n && s[i] == ' ') i++;

        // Check if the string is empty after trimming spaces
        if (i == n) return 0;

        // Handle sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            // Clamp result if it exceeds int range
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;
            i++;
        }

        return static_cast<int>(ans * sign);
    }
};
