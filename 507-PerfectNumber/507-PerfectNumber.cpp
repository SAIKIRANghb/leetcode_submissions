// Last updated: 11/25/2026, 3:47:12 PM
// class Solution {
// public:
//     bool checkPerfectNumber(int num) {
//         int srt = sqrt(num);
//         int res = 1;
//         for(int i = 2;i <= srt;i++){
//             if(num / i == i){
//                 res += i;
//             }
//             else if(num % i == 0){
//                 res += (num / i) + i;
//             }
//         }
//         if(res == num)return true;
//         return false;
//     }
// };
#include <cmath>

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false; // Edge case
        
        int res = 1;
        int srt = sqrt(num);
        
        for (int i = 2; i <= srt; ++i) {
            if (num % i == 0) {
                res += i + (num / i);
            }
        }
        
        if (srt * srt == num) {
            res -= srt; // Avoid adding square root twice
        }
        
        return res == num;
    }
};
