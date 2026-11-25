// Last updated: 11/25/2026, 3:41:05 PM
class Solution {
public:
    long long coloredCells(int n) { return 1 + (long long)n * (n - 1) * 2; }
};