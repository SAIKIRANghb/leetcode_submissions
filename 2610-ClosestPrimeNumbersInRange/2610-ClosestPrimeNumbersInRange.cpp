// Last updated: 11/25/2026, 3:41:16 PM
class Solution {
public:
    void Sieve(vector<int> & prime){
        int n = 1e6;
        prime[0] = prime[1] = 0;
        for(int i = 2;i * i <= n;i++){
            if(prime[i] == 1){
                for(int j = i*i;j <= n;j += i){
                    prime[j] = 0;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        int n = 1e6;
        vector<int>prime(n + 1,1);
        Sieve(prime);
        vector<int>ans(2,-1);
        int prevPrime = -1;
        for(int i = max(left,2);i <= right;i++){
            if(prime[i]){
                if(prevPrime != -1){
                    if(ans[0] == -1 || (i - prevPrime < ans[1] - ans[0])){
                        ans[0] = prevPrime;
                        ans[1] = i;
                    }
                }
                prevPrime = i;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     void Sieve(vector<int>& prime) {
//         int n = 1e6;
//         prime[0] = prime[1] = 0; // 0 and 1 are not prime numbers
//         for (int i = 2; i * i <= n; i++) {
//             if (prime[i] == 1) {
//                 for (int j = i * i; j <= n; j += i) {
//                     prime[j] = 0; // Mark multiples of i as non-prime
//                 }
//             }
//         }
//     }

//     vector<int> closestPrimes(int left, int right) {
//         int n = 1e6;
//         vector<int> prime(n + 1, 1); // Initialize all numbers as prime
//         Sieve(prime); // Mark non-prime numbers using the Sieve

//         vector<int> ans(2, -1); // Store the closest pair of primes
//         int prevPrime = -1;

//         for (int i = max(left, 2); i <= right; i++) {
//             if (prime[i]) { // Check if i is a prime
//                 if (prevPrime != -1) {
//                     if (ans[0] == -1 || i - prevPrime < ans[1] - ans[0]) {
//                         ans[0] = prevPrime;
//                         ans[1] = i;
//                     }
//                 }
//                 prevPrime = i;
//             }
//         }

//         return ans;
//     }
// };
