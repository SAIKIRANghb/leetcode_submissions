// Last updated: 11/25/2026, 3:49:47 PM
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        if(N < 0) N *= -1;
        while(N > 0){
            if(N % 2 == 1){
                ans = ans*x;
                N = N - 1;
            }
            else{
                N = N / 2;
                x = x * x;
            }
        }
        if(n < 0)ans = (1.0 / ans);
        return ans;
    }
};