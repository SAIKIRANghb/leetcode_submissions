// Last updated: 11/25/2026, 3:43:03 PM
// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         int n = boxes.size();
//         if(n == 1)return {1};
//         vector<int>prefix(n,0);
//         vector<int>suffix(n,0);
//         for(int i = 0;i<n;i++){
//             if(boxes[i] == '1'){
//                 prefix[i] = i;
//             }
//             if(boxes[n - 1 - i] == '1'){
//                 suffix[n - 1 - i] = n - 1 - i;
//             }
//         }
//         // for(int i = 1;i < n - 1;i++){
//         //     prefix[i] += prefix[i - 1];
//         //     suffix[n - 1 - i] += suffix[n - i];
//         // }
//         // prefix[n - 1] += prefix[n - 2];
//         // suffix[0] += suffix[1];
//         vector<int>prefix1s(n,0);
//         vector<int>suffix1s(n,0);

//         if(boxes[0] == '1')prefix1s[0] = 1;
//         if(boxes[n-1] == '1')suffix1s[n-1] = 1;
//         for(int i = 1;i < n - 1;i++){
//             if(boxes[i] == '1'){
//                 prefix1s[i] = 1;
//             }
//             if(boxes[n - 1 - i] == '1'){
//                 suffix1s[n - 1 - i] = 1;
//             }
//             suffix1s[n - 1 - i] += suffix1s[n - i];
//             prefix1s[i] += prefix1s[i - 1];
            
//             prefix[i] += prefix[i - 1];
//             suffix[n - 1 - i] += suffix[n - i];
//         }
//         prefix1s[n - 1] += prefix1s[n - 2];
//         suffix1s[0] += suffix1s[1];

//         prefix[n - 1] += prefix[n - 2];
//         suffix[0] += suffix[1];

//         vector<int>ans(n , -1);

//         for(int i = 0;i<n;i++){
//             ans[i] = (prefix[i] - i*suffix1s[i]) + (suffix[i] - (n - 1 - i)*suffix1s[i]);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         int n = boxes.size();
//         vector<int> prefix(n, 0);
//         vector<int> suffix(n, 0);
//         vector<int> prefix1s(n, 0);
//         vector<int> suffix1s(n, 0);
        
//         if (boxes[0] == '1') prefix1s[0] = 1;
//         if (boxes[n - 1] == '1') suffix1s[n - 1] = 1;

//         // Calculate prefix sums
//         for (int i = 1; i < n; ++i) {
//             prefix1s[i] = prefix1s[i - 1] + (boxes[i] == '1' ? 1 : 0);
//             prefix[i] = prefix[i - 1] + prefix1s[i - 1];
//         }

//         // Calculate suffix sums
//         for (int i = n - 2; i >= 0; --i) {
//             suffix1s[i] = suffix1s[i + 1] + (boxes[i] == '1' ? 1 : 0);
//             suffix[i] = suffix[i + 1] + suffix1s[i + 1];
//         }

//         // Calculate the result
//         vector<int> ans(n, 0);
//         for (int i = 0; i < n; ++i) {
//             ans[i] = prefix[i] + suffix[i];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int count = 0, steps = 0;

        // Calculate prefix sum of operations
        for (int i = 0; i < n; ++i) {
            ans[i] += steps;
            if (boxes[i] == '1') {
                ++count;
            }
            steps += count;
        }

        count = 0;
        steps = 0;

        // Calculate suffix sum of operations
        for (int i = n - 1; i >= 0; --i) {
            ans[i] += steps;
            if (boxes[i] == '1') {
                ++count;
            }
            steps += count;
        }

        return ans;
    }
};
