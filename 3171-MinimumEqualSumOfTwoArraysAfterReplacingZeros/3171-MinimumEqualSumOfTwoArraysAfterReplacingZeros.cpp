// Last updated: 11/25/2026, 3:40:22 PM
// class Solution {
// public:
//     long long minSum(vector<int>& nums1, vector<int>& nums2) {
//         long long T1 = accumulate(nums1.begin(),nums1.end(),0);
//         long long T2 = accumulate(nums2.begin(),nums2.end(),0);
//         if(T1 < T2){
//             swap(T1,T2);
//         }
//         long long diff = T1 - T2;
//         if(diff < 0)return -1;

//         return min(T1 - diff,T2 - diff) + T2;
//     }
// };
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }
        for (int i : nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }
        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
    }
};