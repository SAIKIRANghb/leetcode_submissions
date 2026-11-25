// Last updated: 11/25/2026, 3:43:42 PM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int prefEvens = 1;
        int prefOdds = 0;
        int prefSum = 0;
        int MOD = 1e9 + 7;
        int n = arr.size();
        int cntOddSubArrs = 0;
        for(int i = 0;i < n;i++){
            prefSum += arr[i];
            if(prefSum % 2 == 0){
                cntOddSubArrs += prefOdds;
                prefEvens++;
            }else{
                cntOddSubArrs += prefEvens;
                prefOdds++;
            }
            cntOddSubArrs %= MOD;
        }
        return cntOddSubArrs;
    }
};

// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         int n = arr.size();
//         int MOD = 1e9 + 7;

//         vector<int>dpOdd(n,0);
//         vector<int>dpEven(n,0);

//         for(int &num : arr){
//             num %= 2;
//         }
//         if(arr[0] == 1){
//             dpOdd[0] = 1;
//         }else{
//             dpEven[0] = 1;
//         }

//         for(int num = 1;num < n;num++){
//             if(arr[num] == 1){
//                 dpOdd[num] = (dpEven[num - 1] + 1) % MOD;
//                 dpEven[num] = dpOdd[num - 1];
//             }else{
//                 dpOdd[num] = dpOdd[num - 1];
//                 dpEven[num] = (dpEven[num - 1] + 1) % MOD;
//             }
//         }

//         int cnt = 0;
//         for(auto oddCnt : dpOdd){
//             cnt += oddCnt;
//             cnt %= MOD;
//         }
//         return cnt;
//     }
// };