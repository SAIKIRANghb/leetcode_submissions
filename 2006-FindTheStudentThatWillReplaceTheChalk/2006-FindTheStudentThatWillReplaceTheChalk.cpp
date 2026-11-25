// Last updated: 11/25/2026, 3:42:46 PM
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long>prefSum(n,0);
        prefSum[0] = chalk[0];
        for(int i = 1;i<n;i++){
            prefSum[i] = prefSum[i - 1] + chalk[i];
        }
        long long total = prefSum[n-1];
        int rem = k % total;
        // if(rem == 0)return 0;
        int low = 0,high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(prefSum[mid] <= rem){
                low = mid+1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int chalkReplacer(vector<int>& chalk, int k) {
//         long long sum = 0;
//         for(int num : chalk){
//             sum += num;
//         }
//         while(sum <= k){
//              k -= sum;
//         }
//         for(int i = 0;i<chalk.size();i++){
//             if(chalk[i] <= k){
//                 k -= chalk[i];
//             }else{
//                 return i;
//             }
//         }
//         return -1;
//     }
// };