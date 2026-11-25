// Last updated: 11/25/2026, 3:44:03 PM
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the adjacency matrix
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        
        // Fill the graph with given edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph[u][v] = weight;
            graph[v][u] = weight;
        }

        int minCity = -1;
        int minNeighbourCount = INT_MAX;

        // Iterate over each city to calculate shortest paths to all other cities
        for (int start = 0; start < n; ++start) {
            vector<int> dist(n, INT_MAX);
            vector<bool> vis(n, false);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            dist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();

                if (vis[u]) continue;
                vis[u] = true;

                for (int v = 0; v < n; ++v) {
                    if (graph[u][v] != INT_MAX && !vis[v]) {
                        int newDist = dist[u] + graph[u][v];
                        if (newDist < dist[v]) {
                            dist[v] = newDist;
                            pq.push({newDist, v});
                        }
                    }
                }
            }

            // Count the number of neighbors within the distance threshold
            int neighbourCount = 0;
            for (int i = 0; i < n; ++i) {
                if (dist[i] <= distanceThreshold) {
                    ++neighbourCount;
                }
            }

            // Find the city with the minimum neighbor count
            if (neighbourCount <= minNeighbourCount) {
                minNeighbourCount = neighbourCount;
                minCity = start;
            }
        }

        return minCity;
    }
};

// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>>graph(n + 1,vector<int>(n + 1,-1));
//         int esz = edges.size();
//         for(int i = 0;i<esz;i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int weight = edges[i][2];
//             graph[u][v] = weight;
//             graph[v][u] = weight;
//         }
//         for(int i = 0;i<n + 1;i++){
//             graph[i][n] = 0;
//             graph[n][i] = 0;
//         }
//         vector<bool>vis(n+1,false);
//         vector<int>weights(n+1,INT_MAX);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         weights[n] = 0;
//         vis[n] = true;
//         pq.push({0,n});
//         while(!pq.empty()){
//             auto top = pq.top();
//             pq.pop();
//             int node = top.second;
//             int weight = top.first;
//             vis[node] = true;
//             for(int i = 0;i<graph[node].size();i++){
//                 if(graph[node][i] != -1 || vis[i])continue;
//                 weights[i] = min(weights[i],weight + graph[node][i]);
//                 pq.push({weights[i],i});
//             }
//         }
//             int city = -1;
//             int neighbours = 0; 
//             int minCity = -1;
//             int minNeighbours = INT_MAX;
//             for(int i = 0;i<n;i++){
//                 city = i;
//                 for(int j = 0;j<n;j++){
//                     if(graph[i][j] == -1)continue;
//                     if(weights[j] <= distanceThreshold){
//                         neighbours++;
//                     }
//                 }
//                 if(minNeighbours >= neighbours){
//                     minNeighbours = neighbours;
//                     minCity = city;
//                 }
//             }
//         return city;
//     }
// };

// #include <vector>
// #include <queue>
// #include <climits>

// using namespace std;

// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         // Initialize the graph with INF distances
//         vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        
//         for (const auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             int weight = edge[2];
//             graph[u][v] = weight;
//             graph[v][u] = weight;
//         }
        
//         // Dijkstra's algorithm to find shortest paths from each city
//         auto dijkstra = [&](int start) {
//             vector<int> dist(n, INT_MAX);
//             vector<bool> visited(n, false);
//             priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//             dist[start] = 0;
//             pq.push({0, start});
            
//             while (!pq.empty()) {
//                 int u = pq.top().second;
//                 int d = pq.top().first;
//                 pq.pop();
                
//                 if (visited[u]) continue;
//                 visited[u] = true;
                
//                 for (int v = 0; v < n; ++v) {
//                     if (graph[u][v] != INT_MAX && !visited[v]) {
//                         if (dist[u] + graph[u][v] < dist[v]) {
//                             dist[v] = dist[u] + graph[u][v];
//                             pq.push({dist[v], v});
//                         }
//                     }
//                 }
//             }
//             return dist;
//         };
        
//         int resultCity = -1;
//         int minNeighbors = INT_MAX;
        
//         for (int i = 0; i < n; ++i) {
//             vector<int> dist = dijkstra(i);
//             int count = 0;
            
//             for (int j = 0; j < n; ++j) {
//                 if (i != j && dist[j] <= distanceThreshold) {
//                     ++count;
//                 }
//             }
            
//             if (count < minNeighbors || (count == minNeighbors && i > resultCity)) {
//                 minNeighbors = count;
//                 resultCity = i;
//             }
//         }
        
//         return resultCity;
//     }
// };
