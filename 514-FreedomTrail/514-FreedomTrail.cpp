// Last updated: 11/25/2026, 3:47:09 PM
//Top-Down DP
// class Solution {
// public:
//     vector<vector<int>>dp;
//     int disBetween(int ringIndex,int i,int n){
//         int dis1 = abs(ringIndex - i);
//         int dis2 = n - dis1;
//         return min(dis1,dis2);
//     }
//     int findMinSteps(int ringIndex,int keyIndex,string ring, string key){
//         int n = ring.size();
//         if(key.size() == keyIndex){
//             return 0;
//         }
//         if(dp[ringIndex][keyIndex] != -1){
//             return dp[ringIndex][keyIndex];
//         }
//         int minPath = INT_MAX;
//         for(int i = 0;i<n;i++){
//             if(key[keyIndex] == ring[i]){
//                 int randPath = 1 + disBetween(ringIndex,i,n) + findMinSteps(i,keyIndex + 1,ring,key);
//                 minPath = min(minPath,randPath);
//             }
//         }
//         return dp[ringIndex][keyIndex] = minPath;
//     }
//     int findRotateSteps(string ring, string key) {
//         int m = ring.size();
//         int n = key.size();
//         dp = vector<vector<int>>(m,vector<int>(n,-1));
//         return findMinSteps(0,0,ring,key);
//     }
// };

//Bottom-Up DP
// class Solution {
// public:

//     int disBetween(int ringIndex,int i,int n){
//         int dis1 = abs(ringIndex - i);
//         int dis2 = n - dis1;
//         return min(dis1,dis2);
//     }

//     int findRotateSteps(string ring, string key) {
//         int m = ring.size();
//         int n = key.size();
//          vector<vector<int>> dp = vector<vector<int>>(m,vector<int>(n+1,0));
//         for(int keyInd = n-1;keyInd >= 0;keyInd--){
//             for(int ringInd = 0;ringInd < m;ringInd++){
//                 int minSteps = INT_MAX;
//                 for(int i = 0;i<m;i++){
//                     if(ring[i] == key[keyInd]){
//                         int totalSteps = 1 + disBetween(ringInd,i,m) + dp[i][keyInd + 1];
//                         minSteps = min(minSteps,totalSteps);
//                     }
//                 }
//                 dp[ringInd][keyInd] = minSteps;
//             }
//         }
//         return dp[0][0];
//     }
// };

//Optimized DP
// class Solution {
// public:

//     int disBetween(int ringIndex,int i,int n){
//         int dis1 = abs(ringIndex - i);
//         int dis2 = n - dis1;
//         return min(dis1,dis2);
//     }

//     int findRotateSteps(string ring, string key) {
//         int m = ring.size();
//         int n = key.size();
//          vector<int>currDp(m,0);
//          vector<int>prevDp(m,0);
//         for(int keyInd = n-1;keyInd >= 0;keyInd--){
//             for(int ringInd = 0;ringInd < m;ringInd++){
//                 int minSteps = INT_MAX;
//                 for(int i = 0;i<m;i++){
//                     if(ring[i] == key[keyInd]){
//                         int totalSteps = 1 + disBetween(ringInd,i,m) + prevDp[i]; //keyInd + 1 Column
//                         minSteps = min(minSteps,totalSteps);
//                     }
//                 }
//                 currDp[ringInd] = minSteps; //keyInd column
//             }
//             prevDp = currDp; //if keyInd changes then prevDp changes to currDp
//         }
//         return currDp[0];
//     }
// };

//Dijkstra

#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dis(int ringIndex, int i, int n) {
        int dis1 = abs(ringIndex - i);
        int dis2 = n - dis1;
        return min(dis1, dis2);
    }

    int findRotateSteps(string ring, string key) {
        int m = key.size();
        int n = ring.size();
        
        unordered_map<char, vector<int>> charInd;
        for (int i = 0; i < n; i++) {
            char ch = ring[i];
            charInd[ch].push_back(i);
        }

        // Priority queue: {steps, ringIndex, keyIndex}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        unordered_set<string> seen;

        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int totalSteps = v[0];
            int ringInd = v[1];
            int keyInd = v[2];

            if (keyInd == m) return totalSteps;

            string currentState = to_string(ringInd) + "_" + to_string(keyInd);
            if (seen.count(currentState)) continue;
            seen.insert(currentState);

            for (int nextInd : charInd[key[keyInd]]) {
                int steps = totalSteps + dis(ringInd, nextInd, n) + 1;
                pq.push({steps, nextInd, keyInd + 1});
            }
        }
        return -1; // This should never be reached if input is valid
    }
};
