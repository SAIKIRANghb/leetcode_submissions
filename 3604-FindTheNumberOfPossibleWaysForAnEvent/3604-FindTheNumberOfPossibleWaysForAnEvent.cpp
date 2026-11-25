// Last updated: 11/25/2026, 3:38:32 PM
int comb[1001][1001] = {}, dp[1001][1001] = {}, mod = 1000000007;
class Solution {
public:
long long modPow(int x, int y, int m)
{
    if (y == 0)
        return 1;
    long long p = modPow(x, y / 2, m) % m;
    p = (p * p) % m;
    return y % 2 ? (p * x) % m : p;
}    
int numberOfWays(int n, int x, int y) {
    if (comb[0][0] == 0) {      
        comb[0][0] = dp[0][0] = 1;
        for (int n = 1; n < 1001; ++n) {
            comb[n][0] = 1;
            for (long long x = 1; x <= n; ++x) {
                comb[n][x] = (comb[n - 1][x - 1] + comb[n - 1][x]) % mod;
                dp[n][x] = x * (dp[n - 1][x - 1] + dp[n - 1][x]) % mod;
            }
        }
    }
    long long res = 0;
    for (int st = 1; st <= min(n, x); ++st)
        res = (res + modPow(y, st, mod) * comb[x][st] % mod * dp[n][st] % mod) % mod;
    return res;
}
};