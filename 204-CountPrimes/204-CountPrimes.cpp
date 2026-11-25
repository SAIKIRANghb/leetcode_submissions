// Last updated: 11/25/2026, 3:48:08 PM
#include <vector>

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;
        std::vector<bool> prime(n, true);
        int count = 0;
        for (int i = 2; i * i < n; i++) {
            if (isPrime(i)) {
                for (int j = i * i; j < n; j += i) {
                    if (prime[j]) {
                        prime[j] = false;
                        count++;
                    }
                }
            }
        }
        return n - count - 2;
    }
};
