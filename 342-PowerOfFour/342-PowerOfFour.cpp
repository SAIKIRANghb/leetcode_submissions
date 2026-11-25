// Last updated: 11/25/2026, 3:47:31 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1)return true;
        if(n < 4)return false;
        int srt = sqrt(n);
        return n > 0 && (n & (n - 1)) == 0 && (srt*srt == n);
    }
};