// Last updated: 11/25/2026, 3:38:15 PM
// class Solution {
// public:
//     // BFS from a single start node counting only nodes at even distances
//     int bfs(int start, vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<bool> vis(n, false);
//         queue<pair<int, int>> q;  // {node, depth}
//         q.push({start, 0});
//         vis[start] = true;
//         int count = 0;

//         while (!q.empty()) {
//             auto [u, depth] = q.front();
//             q.pop();
//             if (depth % 2 == 0) {
//                 count++;  // count only nodes at even depth (even number of edges)
//             }
//             for (int v : graph[u]) {
//                 if (!vis[v]) {
//                     vis[v] = true;
//                     q.push({v, depth + 1});
//                 }
//             }
//         }
//         return count;
//     }

//     // Build graph and run BFS for each node
//     vector<int> build(vector<vector<int>>& edges) {
//         int n = edges.size() + 1;
//         vector<vector<int>> graph(n);
//         for (auto& e : edges) {
//             graph[e[0]].push_back(e[1]);
//             graph[e[1]].push_back(e[0]);
//         }

//         vector<int> count(n);
//         for (int i = 0; i < n; i++) {
//             count[i] = bfs(i, graph);
//         }
//         return count;
//     }

//     vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
//         vector<int> count1 = build(edges1);
//         vector<int> count2 = build(edges2);
//         int maxTargetOf2 = *max_element(count2.begin(), count2.end());
//         int n = edges1.size() + 1;
//         vector<int> res(n);

//         for (int i = 0; i < n; i++) {
//             res[i] = count1[i] + maxTargetOf2;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int dfs(int node, int parent, int depth,
            const vector<vector<int>>& children, vector<int>& color) {
        int res = 1 - depth % 2;
        color[node] = depth % 2;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        int res = dfs(0, -1, 0, children, color);
        return {res, n - res};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> color1(n);
        vector<int> color2(m);
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);
        vector<int> res(edges1.size() + 1);
        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + max(count2[0], count2[1]);
        }
        return res;
    }
};