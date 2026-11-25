// Last updated: 11/25/2026, 3:42:31 PM
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a; // Base case: when b is 0, gcd is a.
        return gcd(b, a % b); // Recursive case: gcd(b, a % b)
    }

    int findGCD(vector<int>& nums) {
        int maxN = INT_MIN;
        int minN = INT_MAX;
        
        // Find the maximum and minimum values in the array
        for (auto it : nums) {
            maxN = max(maxN, it);
            minN = min(minN, it);
        }
        int a = maxN , b = minN;

        while(a > 0 && b > 0){
            if(a > b) a = a % b;
            else b = b % a;
        }
        
        if(a == 0)return b;
        else return a;
        // Return the GCD of the maximum and minimum values
        // return gcd(maxN, minN);
    }
};
