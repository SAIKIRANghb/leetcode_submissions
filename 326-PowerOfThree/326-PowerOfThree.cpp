// Last updated: 11/25/2026, 3:47:33 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467%n==0;
    }
};

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n == 1)return true;
//         if(n < 3) return false;
//         int num = n;
//         while(num > 1){
//             if(num % 3 != 0)return false;
//             num = num / 3;
//         }
//         return true;
//     }
// };