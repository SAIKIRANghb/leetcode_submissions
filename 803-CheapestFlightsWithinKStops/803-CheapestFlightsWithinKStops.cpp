// Last updated: 11/25/2026, 3:46:12 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Construct the graph using adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            graph[from].emplace_back(to, cost);
        }

        // Priority queue to store {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Distance array to store minimum cost to reach each node with given number of stops
        vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX)); // k + 2 to handle 0 to k stops
        minCost[src][0] = 0;

        // Push source node with 0 stops and cost 0
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int cost = top[0];
            int u = top[1];
            int stops = top[2];

            if (u == dst) return cost; // Found the destination

            if (stops > k) continue; // Skip if exceeds maximum stops

            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int weightUV = neighbor.second;
                int newCost = cost + weightUV;

                if (newCost < minCost[v][stops + 1]) {
                    minCost[v][stops + 1] = newCost;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }

        return -1; // If destination is not reachable within k stops
    }
};
