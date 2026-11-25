// Last updated: 11/25/2026, 3:41:18 PM
class Solution {
public:
    void addPrimeFactors(int num, unordered_set<int>& primes) {
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                primes.insert(i);
                num /= i;
            }
        }
        if (num > 1) {
            primes.insert(num); 
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes; 
        for (int num : nums) {
            addPrimeFactors(num, primes);
        }
        return primes.size(); 
    }
};
