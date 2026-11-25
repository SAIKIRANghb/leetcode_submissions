// Last updated: 11/25/2026, 3:42:32 PM
#define ll long long
const int MOD = 1e9 + 7;
const ll MAX = LLONG_MAX;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ll>>adjLst(n,vector<ll>(n,MAX));

        vector<ll>dist(n,MAX);
        vector<ll>ways(n,0);

        for(auto &road : roads){
            int u = road[0] , v = road[1],time = road[2];
            adjLst[u][v] = time;
            adjLst[v][u] = time;
        }
        
        priority_queue<vector<ll> , vector<vector<ll>> ,greater<vector<ll>>>pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            vector<ll>top = pq.top();
            pq.pop();
            int u = top[1];
            ll time = top[0];
            for(int i = 0;i < n;i++){
                if(adjLst[u][i] != MAX){
                    ll newTime = adjLst[u][i] + time;
                    if(dist[i] > newTime){
                        dist[i] = newTime;
                        pq.push({newTime,i});
                        ways[i] = ways[u];
                    }else if(dist[i] == newTime){
                        ways[i] = (ways[u] + ways[i]) % MOD;
                    }
                }
            }   
        }
        return ways[n - 1];
    }
};

// #define ll long long
// const int MOD = 1e9 + 7;

// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {

//         vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n, vector<ll>(2, 0)));

//         for (int src = 0; src < n; src++) {
//             for (int dest = 0; dest < n; dest++) {
//                 if (src != dest) {
//                     dp[src][dest][0] = 1e12;
//                     dp[src][dest][1] = 0;
//                 } else {
//                     dp[src][dest][0] = 0;
//                     dp[src][dest][1] = 1;
//                 }
//             }
//         }

//         for (auto& road : roads) {
//             ll u = road[0], v = road[1], time = road[2];
//             dp[u][v][0] = time;
//             dp[v][u][0] = time;
//             dp[u][v][1] = 1;
//             dp[v][u][1] = 1;
//         }
//         for (ll mid = 0; mid < n; mid++) {
//             for (ll src = 0; src < n; src++) {
//                 for (ll dest = 0; dest < n; dest++) {
//                     if(src != mid && mid != dest){
//                         ll newTime = dp[src][mid][0] + dp[mid][dest][0];
//                         if(newTime < dp[src][dest][0]){
//                             dp[src][dest][0] = newTime;
//                             dp[src][dest][1] = (dp[src][mid][1] * dp[mid][dest][1]) % MOD;
//                         }else if(newTime == dp[src][dest][0]){
//                             dp[src][dest][1] = (dp[src][dest][1] + dp[src][mid][1] * dp[mid][dest][1]) % MOD;
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[n - 1][0][1];
//     }
// };

// Optimal i would say if only for one start and end node given
// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         const long long MOD = 1e9 + 7;

//         vector<long long> ways(n, 0);
//         vector<long long> dist(n, LLONG_MAX);

//         int nr = roads.size();

//         vector<vector<long long>> adjLst(n, vector<long long>(n, LLONG_MAX));

//         for(int i = 0; i < nr; i++) {
//             adjLst[roads[i][0]][roads[i][1]] = roads[i][2];
//             adjLst[roads[i][1]][roads[i][0]] = roads[i][2];
//         }

//         priority_queue<vector<long long>, vector<vector<long long>>,
//         greater<vector<long long>>> pq;

//         dist[0] = 0;
//         ways[0] = 1;
//         pq.push({0, 0});  // {distance, node}

//         while(!pq.empty()) {
//             vector<long long> top = pq.top();
//             pq.pop();
//             long long node = top[1];
//             long long time = top[0];

//             for(long long i = 0; i < adjLst[node].size(); i++) {
//                 if(adjLst[node][i] != LLONG_MAX) {
//                     // Relax the edge
//                     long long newTime = time + adjLst[node][i];
//                     if(dist[i] > newTime) {
//                         dist[i] = newTime;
//                         ways[i] = ways[node];
//                         pq.push({newTime, i});
//                     }
//                     else if(dist[i] == newTime) {
//                         ways[i] = (ways[i] + ways[node]) % MOD;
//                     }
//                 }
//             }
//         }
//         return ways[n - 1];
//     }
// };
