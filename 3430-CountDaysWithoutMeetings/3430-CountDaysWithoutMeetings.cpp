// Last updated: 11/25/2026, 3:39:35 PM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int>dayMp;
        int n = meetings.size(); 
        int prev = days;
        for(int i = 0;i < n;i++){
            prev = min(prev,meetings[i][0]);
            dayMp[meetings[i][0]] += 1;
            dayMp[meetings[i][1] + 1] += -1;
        }
        int prefSum = 0;
        int curr = 0;
        int freedays = 0;
        freedays += (prev - 1);
        for(auto &day : dayMp){
            curr = day.first;
            if(prefSum == 0){
                freedays += curr - prev;
            }
            prefSum += day.second;
            prev = curr;
        }
        freedays += days - prev + 1;
        return freedays;
    }
};

//Gives MLE
// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         int n = meetings.size();
//         vector<int>dp(days + 1,0);
//         for(int i = 0;i < n;i++){
//             dp[meetings[i][0]] += 1;
//             if(meetings[i][1] + 1 <= days)dp[meetings[i][1] + 1] += -1;
//         }
//         for(int i = 1;i <= days;i++){
//             dp[i] += dp[i - 1];
//         }
//         int cnt = 0;
//         for(int i = 1;i <= days;i++){
//             if(dp[i] == 0)cnt++;
//         }
//         return cnt;
//     }
// };

