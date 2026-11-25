// Last updated: 11/25/2026, 3:41:08 PM
// class Solution {
// public:
//     int passThePillow(int n, int time) {
//         int rem = time % n;
//         if(n <= time){
//             if((time / n) % 2 == 0){
//                 return rem + 1 ;
//             }
//             return n - (rem + 1);
//         }else{
//             return time + 1;
//         }
//     }
// };

class Solution {
public:
    int passThePillow(int n, int time) {
        if(time > n - 1){
            int rem = time % (n-1);
            if((time / (n-1)) % 2 == 0){
                return rem + 1;
            }else{
                return n - rem;
            }
        }else{
            return time + 1;
        }
    }
};