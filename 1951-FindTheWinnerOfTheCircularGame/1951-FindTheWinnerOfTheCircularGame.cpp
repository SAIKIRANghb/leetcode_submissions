// Last updated: 11/25/2026, 3:42:51 PM
// class Solution {
//     public:

//     int findTheWinner(int n, int k) {
//         queue<int> q;
//         int count = 0;
//         for(int i = 1;i<= n;i++){
//             q.push(i);
//         }
//         while(!q.empty() && q.size() > 1){
//             int f = q.front();
//             q.pop();
//             count++;
//             if(count == k){
//                 count = 0;
//             }else{
//                 q.push(f);
//             }
//         }
//         return q.front();
//     }
// };
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> gone(n, 0);
        int remaining = n; // Number of people remaining
        int current = 0;   // Start from the first person

        while (remaining > 1) {
            // Find the k-th non-eliminated person
            for (int count = 0; count < k; ++current) {
                if (current == n) {
                    current = 0; // Wrap around to the beginning
                }
                if (!gone[current]) {
                    ++count; // Count this person if not eliminated
                }
            }
            
            // Eliminate the k-th person
            gone[current - 1] = 1;
            --remaining;
        }

        // Find the last remaining person
        for (int i = 0; i < n; ++i) {
            if (!gone[i]) {
                return i + 1;
            }
        }

        return -1; // Should not reach here under normal circumstances
    }
};
