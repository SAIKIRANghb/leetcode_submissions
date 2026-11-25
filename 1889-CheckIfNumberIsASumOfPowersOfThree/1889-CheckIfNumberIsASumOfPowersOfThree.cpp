// Last updated: 11/25/2026, 3:43:07 PM
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int num = n;
        int rem = 0;
        while(num > 0){
            rem = num % 3;
            num = num / 3;
            if(rem == 2)return false;
        }
        return true;
    }
};