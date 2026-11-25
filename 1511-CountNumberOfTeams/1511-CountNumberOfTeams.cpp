// Last updated: 11/25/2026, 3:43:53 PM
//BottomUp - DP
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<int>>ascend(n,vector<int>(4,0));
        vector<vector<int>>descend(n,vector<int>(4,0));
        for(int i = 0;i<n;i++){
            ascend[i][1] = 1;
            descend[i][1] = 1;
        }   

        for(int count = 2;count<=3;count++){
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    if(rating[i] < rating[j]){
                        ascend[i][count] += ascend[j][count-1];
                    }
                    if(rating[i] > rating[j]){
                        descend[i][count] += descend[j][count-1];
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += (ascend[i][3] + descend[i][3]);
        }
        return ans;
    }
};




//TopDown - DP
// class Solution {
// public: 
//     unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
    
//     int solve(vector<int>& rating, int i, bool increasing, int count) {
//         if (count == 3) return 1;  // Found a valid team
//         int n = rating.size();
//         if (i >= n) return 0;  // Reached end of the list without forming a valid team

//         // If the result for this state is already computed, return it
//         if (dp[i][increasing][count] != 0) return dp[i][increasing][count];

//         int ans = 0;
//         for (int j = i + 1; j < n; ++j) {
//             if ((increasing && rating[i] < rating[j]) || (!increasing && rating[i] > rating[j])) {
//                 ans += solve(rating, j, increasing, count + 1);
//             }
//         }
//         // Store the result for this state
//         dp[i][increasing][count] = ans;
//         return ans;
//     }
    
//     int numTeams(vector<int>& rating) {
//         int n = rating.size();
//         int ans = 0;
//         // Check for both increasing and decreasing sequences
//         for (int i = 0; i < n; ++i) {
//             ans += solve(rating, i, true, 1);
//             ans += solve(rating, i, false, 1);
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int n = rating.size();
//         if(n < 3)return 0;
//         int ans = 0;
//         for(int i = 1;i<n;i++){
//             int left = i - 1;
//             int right = i + 1;
//             int countLeft = 0;
//             int countRight = 0;
//             while(left >= 0){
//                 if(rating[left] < rating[i]){
//                     countLeft++;
//                 }
//                 left--;
//             }
//             while(right < n){
//                 if(rating[i] < rating[right]){
//                     countRight++;
//                 }
//                 right++;
//             }
//             ans += (countLeft * countRight) + ((i - countLeft)*(n - i - 1 - countRight));
//         }
//         return ans;
//     }
// };
