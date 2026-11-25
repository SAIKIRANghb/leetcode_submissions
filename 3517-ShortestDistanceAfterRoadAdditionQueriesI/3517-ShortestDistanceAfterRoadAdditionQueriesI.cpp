// Last updated: 11/25/2026, 3:38:50 PM
// class Solution {
// public:
//     int bfs(unordered_map<int,vector<int>>mp,int start,int disAtU,vector<int>&dis,int n){
//         queue<int>Q;
//         Q.push(start);
//         int depth = 0;
//         while(!Q.empty()){
//             int sz = Q.size();
//             while(sz--){
//                 int front = Q.front();
//                 Q.pop();
//                 if(front == n - 1){
//                     return depth;
//                 }
//                 vector<int>childs = mp[front];
//                 for(int child : childs){
//                     Q.push(child);
//                     dis[child] = depth;
//                 }
//             }
//             depth++;
//         }
//         return depth;
//     }
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         unordered_map<int,vector<int>>mp;
//         vector<int>ans(n,0);
//         vector<int>dis(n,0);
//         for(int i = 0;i<n-1;i++){
//             vector<int>adjList;
//             adjList.push_back(i + 1);
//             mp[i] = adjList;
//             dis[i] = i;
//         }
//         int qn = queries.size();
//         int shortPath = n - 1;
//         for(int i = 0;i<qn;i++){
//            vector<int>query = queries[i];
//            int u = query[0];
//            int v = query[1];
//            mp[u].push_back(v);
//            int start = u;
//            int disAtU = dis[u];
//            vector<int>tempdis = dis;
//            int res = bfs(mp,start,disAtU,tempdis,n);

//            if(shortPath > res){
//                dis = temp;
//                shortPath = res;
//             }
//         }
//         return shortestPath;
//     }
// };

#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Adjacency list to represent the graph
        vector<vector<int>> adjList(n);
        
        // Initial graph setup with direct roads from city i to i+1
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }
        
        vector<int> result; // Store shortest path lengths for each query
        
        // BFS function to calculate shortest path from city 0 to city n-1
        auto bfs = [&](int start, int target) -> int {
            queue<int> q;
            vector<int> distance(n, -1); // Distance from the start city
            q.push(start);
            distance[start] = 0;
            
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                
                // If we reach the target city, return its distance
                if (current == target) {
                    return distance[target];
                }
                
                for (int neighbor : adjList[current]) {
                    if (distance[neighbor] == -1) { // Not visited
                        distance[neighbor] = distance[current] + 1;
                        q.push(neighbor);
                    }
                }
            }
            
            // If target is unreachable (shouldn't happen in this problem)
            return n;
        };
        
        // Process each query
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            
            // Add the new road to the graph
            adjList[u].push_back(v);
            
            // Calculate the shortest path from city 0 to city n-1
            result.push_back(bfs(0, n - 1));
        }
        
        return result;
    }
};
