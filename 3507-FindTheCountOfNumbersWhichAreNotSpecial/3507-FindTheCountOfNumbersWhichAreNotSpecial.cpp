// Last updated: 11/25/2026, 3:38:57 PM
class Solution {
public:
    
    int nonSpecialCount(int l, int r) {
        int rightMax = sqrt(r);
        vector<bool>isPrime(rightMax + 1,true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2;i*i<=rightMax;i++){
            if(isPrime[i]){
                for(int j = i*i;j<=rightMax;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        int specialCount = 0;
        for(int i = 2;i<=rightMax;i++){
            if(isPrime[i]){
                int squareVal = i*i;
                if(squareVal >= l && squareVal <=r){
                    specialCount++;
                }
            }
        }
        return r - l + 1 - specialCount;
    }
};